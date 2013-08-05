// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)


#pragma once

#include "LikeMagic/Exprs/Expression.hpp"
#include "LikeMagic/Utility/TypeDescr.hpp"
#include "Iocaste/LikeMagicAdapters/API_Io.hpp"
#include "Iocaste/LikeMagicAdapters/ToIoTypeInfo.hpp"

#include <iostream>
#include <stdexcept>

namespace Iocaste { namespace LikeMagicAdapters {

using LikeMagic::Exprs::ExprPtr;
using LikeMagic::Exprs::Expression;
using LikeMagic::Utility::TypeIndex;

class AbstractToIoObjectExpr : public AbstractExpression
{
public:

    virtual bool is_terminal() const { return true; }
    virtual bool is_lazy() const { return false; }

    virtual IoObject* eval_in_context(IoObject *self, IoObject *locals, IoMessage *m) = 0;

    virtual boost::intrusive_ptr<Expression<IoObject*>> clone() const
    {
        throw std::logic_error("clone not implemented yet");
    }

};

template <typename T, typename F>
class ToIoObjectExpr : public AbstractToIoObjectExpr
{
private:
    boost::intrusive_ptr<Expression<T>> from_expr;

private:
    ToIoObjectExpr(boost::intrusive_ptr<Expression<T>> from_expr_) : from_expr(from_expr_) {}

public:

    static ExprPtr create(ExprPtr from_expr)
    {
        AbstractExpression* from_ptr = from_expr.get();
        Expression<T>* from_exact = static_cast<Expression<T>*>(from_ptr);
        ToIoObjectExpr* result = new ToIoObjectExpr<T, F>(from_exact);
        return result;
    }

    virtual LikeMagic::Utility::TypeIndex get_type() const
    {
        return ToIoTypeInfo::create_index();
    }

    virtual IoObject* eval_in_context(IoObject *self, IoObject *locals, IoMessage *m)
    {
        return F::eval_in_context(self, locals, m, from_expr->eval());
    }

    virtual std::string description() const
    {
        return "ToIoObjectExpr from " + from_expr->description();
    }

    virtual void mark() const { from_expr->mark(); }

};


}}
