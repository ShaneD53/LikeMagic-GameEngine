// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#pragma once

#include "LikeMagic/Utility/TupleForEach.hpp"
#include "LikeMagic/Utility/IndexPack.hpp"

#include "LikeMagic/Exprs/Expression.hpp"

#include <string>

namespace LM { namespace methodcall_args {



// Functor used to describe each of the arguments.
struct DescribeArgs
{
    std::string description;

    template <typename T> void operator()(T x)
    {
        if (!description.empty())
            description += ", ";

        description += x->description();
    }
};

// Functor used to mark all the io objects owned by the arguments
struct MarkArgs
{
    template <typename T> void operator()(T x)
    {
        x->mark();
    }
};

template <typename T, typename ArgTuple>
std::string description(T target, ArgTuple args)
{
    DescribeArgs f;
    tuple_for_each(f, args);
    return "(" + target->description() + ").method(" + f.description + ")";
}

template <typename ArgTuple>
std::string description(ArgTuple args)
{
    DescribeArgs f;
    tuple_for_each(f, args);
    return "static method(" + f.description + ")";
}

template <typename ArgTuple, int... Indices>
void mark_args(ArgTuple args, IndexPack<Indices...>)
{
    MarkArgs f;
    tuple_for_each(f, args);
}


}}
