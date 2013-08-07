// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)


#pragma once

#include "LikeMagic/TypeSystem.hpp"
#include "LikeMagic/Exprs/Term.hpp"

#include "LikeMagic/Utility/TypeDescr.hpp"
#include "LikeMagic/Utility/FuncPtrTraits.hpp"
#include "LikeMagic/Utility/MakeCall.hpp"

#include "LikeMagic/Exprs/methodcall_args.hpp"

#include "LikeMagic/CallTargets/CallTarget.hpp"
#include "LikeMagic/Generators/MemberKind.hpp"

// When there are no args, args_tuple does not get expanded below and therefore is set but unused.
// GCC no longer recognizes this option?
//#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

namespace LikeMagic { namespace CallTargets {

using namespace LikeMagic::Exprs;
using namespace LikeMagic::Utility;
using namespace LikeMagic::Generators;

template <typename R, typename... Args>
class StaticMethodCallTarget : public CallTarget
{
public:
    typedef std::tuple<boost::intrusive_ptr<Expression<Args>>...> ArgTuple;
    typedef typename MakeIndexPack<sizeof...(Args)>::type IPack;
    typedef R (*F)(Args...);

private:

    F func_ptr;

    // Handle functions that return a value
    template<typename R_, int... Indices>
    boost::intrusive_ptr<Expression<R_&>>
    build_method_call(ArgList args, TypePack<R_>, IndexPack<Indices...>) const
    {
        if (args.size() != sizeof...(Indices))
            throw std::logic_error("Wrong number of arguments.");

        auto args_tuple(std::make_tuple(type_system->try_conv<Args>(args[Indices])...));

        boost::intrusive_ptr<Expression<R&>> result = Term<R, true>::create(
            (*func_ptr)(std::get<Indices>(args_tuple)->eval()...)
        );

        return result;
    }

    // Handle functions that do not return a value
    template<int... Indices>
    boost::intrusive_ptr<Expression<void>>
    build_method_call(ArgList args, TypePack<void>, IndexPack<Indices...>) const
    {
        if (args.size() != sizeof...(Indices))
            throw std::logic_error("Wrong number of arguments.");

        auto args_tuple = std::make_tuple(type_system->try_conv<Args>(args[Indices])...);

        (*func_ptr)(std::get<Indices>(args_tuple)->eval()...);

        return Term<void, true>::create();
    }

public:

    StaticMethodCallTarget(F func_ptr_) : func_ptr(func_ptr_) {}

    virtual ExprPtr call(ExprPtr target, ArgList args) const
    {
        return build_method_call(args, TypePack<R>(), IPack());
    }

    virtual TypeInfoList get_arg_types() const
    {
        return make_arg_list(TypePack<Args...>());
    }
};

}}
