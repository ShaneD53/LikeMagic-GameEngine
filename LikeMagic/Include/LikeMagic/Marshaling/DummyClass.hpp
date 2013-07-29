// LikeMagic C++ Binding Library
// Copyright 2008-2011 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#pragma once

#include "LikeMagic/Marshaling/AbstractClassImplementation.hpp"
#include "LikeMagic/CallTargets/ConstructorCallTarget.hpp"
#include "LikeMagic/TypeConv/NumberConv.hpp"
#include "LikeMagic/TypeConv/ImplicitConv.hpp"
#include "LikeMagic/TypeConv/BaseConv.hpp"
#include "LikeMagic/TypeConv/AddrOfConv.hpp"

#include "LikeMagic/CallTargets/FieldGetterTarget.hpp"
#include "LikeMagic/CallTargets/FieldSetterTarget.hpp"
#include "LikeMagic/CallTargets/ArrayFieldGetterTarget.hpp"
#include "LikeMagic/CallTargets/ArrayFieldSetterTarget.hpp"
#include "LikeMagic/CallTargets/CustomFieldGetterTarget.hpp"
#include "LikeMagic/CallTargets/CustomFieldSetterTarget.hpp"

#include "LikeMagic/SFMO/ClassExpr.hpp"

namespace LikeMagic { namespace Marshaling {

using LikeMagic::AbstractTypeSystem;
using LikeMagic::NamespacePath;

template <typename T>
class DummyClass : public AbstractClassImplementation
{
protected:

    TypeIndex type;

public:

    DummyClass(TypeIndex type_, std::string name_, AbstractTypeSystem& type_system_, NamespacePath const namespace_) : AbstractClassImplementation(name_, type_system_, namespace_), type(type_)
    {
    }

    virtual TypeIndex get_type() const { return type; }

    virtual bool class_is_copyable() const { return true; }

    virtual AbstractCppObjProxy* create_class_proxy() const
    {
        return
            // Whereas regular class returns a proxy on type T by reference,
            // DummyClass uses call-by-pointer.  This is so that the void
            // type will result in "void*" because a "void&" is illegal.
            // It doesn't matter whether we use call by reference or
            // call by pointer, because LikeMagic supports both.
            ExprProxy::create
            (
                ClassExpr<T*>::create(),
                type_system
            );
    }
};


}}
