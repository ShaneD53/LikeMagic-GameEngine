// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#pragma once

#include "LikeMagic/Mirrors/CallTarget.hpp"

#include "LikeMagic/CallTargets/Delegate.hpp"

namespace LM {

template <typename R>
class ArrayFieldSetterTarget : public CallTarget
{
public:
    typedef R (Delegate::*F)[];

private:
    F const f_ptr;
    TypeIndex const actual_type;
    size_t array_size;

public:

    ArrayFieldSetterTarget(F f_ptr_, TypeIndex actual_type_, size_t array_size_)
        : f_ptr(f_ptr_), actual_type(actual_type_), array_size(array_size_) {}

    virtual ExprPtr call(ExprPtr target, ArgList args) const
    {
        ExprPtr wardens[2];
        ExprPtr target_warden;
        auto target_check = type_system->try_conv(target, actual_type);
        Delegate* target_obj = EvalAs<Delegate*>::value(target_check, target_warden);
        (target_obj->*f_ptr)[EvalAs<size_t>::value(args[0], wardens[0])]
            = EvalAs<R const&>::value(args[1], wardens[1]);
        return 0;
    }

    virtual TypeInfoList const& get_arg_types() const
    {
        static TypeInfoList arg_types = MakeArgList<size_t, R const&>::value();
        return arg_types;
    }

    virtual bool is_inherited() const { return true; }
};

}
