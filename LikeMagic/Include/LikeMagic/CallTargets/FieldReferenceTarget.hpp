// LikeMagic C++ Binding Library
// Copyright 2008-2011 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#pragma once

#include "LikeMagic/Utility/SetField.hpp"

#include "LikeMagic/CallTargets/AbstractCallTargetSelector.hpp"

#include "boost/utility/enable_if.hpp"
#include "boost/type_traits/is_same.hpp"
#include "boost/type_traits/is_void.hpp"

#include "LikeMagic/SFMO/ExprProxy.hpp"

#include "LikeMagic/SFMO/Reference.hpp"

namespace LikeMagic { namespace CallTargets {

using namespace LikeMagic::Utility;
using namespace LikeMagic::SFMO;

template <typename T, typename FieldPtr>
class FieldReferenceTarget : public AbstractCallTargetSelector
{
private:
    typedef T& CallAs;

    FieldPtr f_ptr;

    typedef FieldPtrTraits<FieldPtr, CallAs> Traits;

    typedef typename Traits::R& RType;

public:

    //static bool const is_const_func = true;

    FieldReferenceTarget(FieldPtr f_ptr_, AbstractTypeSystem const& type_system_) : AbstractCallTargetSelector(type_system_), f_ptr(f_ptr_) {}

    virtual ExprPtr call(ExprPtr target, ArgList args) const
    {
        return Reference<RType>::create(
                    SetField<CallAs>::get(type_system.try_conv<CallAs>(target)->eval(), f_ptr));
    }

    virtual TypeInfoList get_arg_types() const
    {
        return make_arg_list(TypePack<>());
    }

};

}}
