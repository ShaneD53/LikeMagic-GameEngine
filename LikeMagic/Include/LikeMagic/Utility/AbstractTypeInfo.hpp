// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#pragma once

#include <typeinfo>
#include <stdexcept>
#include <iostream>
#include <vector>

#include "boost/intrusive_ptr.hpp"
#include "boost/functional/hash.hpp"

#include "LikeMagic/Utility/TypeInfoCache.hpp"
#include "LikeMagic/Utility/KeyWrapper.hpp"

namespace LikeMagic { namespace Utility {

class AbstractTypeInfo;
void intrusive_ptr_add_ref(AbstractTypeInfo const* p);
void intrusive_ptr_release(AbstractTypeInfo const* p);

class AbstractTypeInfo
{
public:
    typedef boost::intrusive_ptr<AbstractTypeInfo const> TypeInfoPtr;
    typedef KeyWrapper<AbstractTypeInfo const> TypeInfoKey;

private:
    friend void intrusive_ptr_add_ref(AbstractTypeInfo const* p);
    friend void intrusive_ptr_release(AbstractTypeInfo const* p);

    mutable int ref_count;
    mutable bool has_cached_hash;
    mutable std::size_t cached_hash;

protected:
    AbstractTypeInfo();
    virtual ~AbstractTypeInfo();

    virtual std::string get_system() const = 0;
    virtual bool less(const AbstractTypeInfo& that) const = 0;
    virtual bool equals(const AbstractTypeInfo& that) const = 0;
    virtual std::size_t calc_hash() const = 0;

public:

    bool operator <(const AbstractTypeInfo& that) const
    {
        if (this->get_system() < that.get_system())
            return true;
        else if (that.get_system() < this->get_system())
            return false;
        else
            return this->less(that);
    }

    bool operator ==(const AbstractTypeInfo& that) const
    {
        if (this->get_system() != that.get_system())
            return false;
        else
            return this->equals(that);
    }


    virtual bool get_ptr_is_const() const { return false; }

    virtual bool get_obj_is_const() const { return false; }

    virtual bool get_is_ref() const { return false; }

    virtual bool get_is_ptr() const { return false; }

    virtual TypeInfoPtr bare_type() const
    {
        return this;
    }

    virtual TypeInfoPtr as_const_obj_type() const
    {
        throw std::logic_error("Type variation as_const_obj_type undefined on " + description());
    }

    virtual TypeInfoPtr as_nonconst_obj_type() const
    {
        throw std::logic_error("Type variation as_nonconst_obj_type undefined on " + description());
    }

    virtual TypeInfoPtr as_const_ptr_type() const
    {
        throw std::logic_error("Type variation as_const_ptr_type undefined on " + description());
    }

    virtual TypeInfoPtr as_nonconst_ptr_type() const
    {
        throw std::logic_error("Type variation as_nonconst_ptr_type undefined on " + description());
    }

    virtual TypeInfoPtr remove_reference() const
    {
        throw std::logic_error("Type variation remove_reference undefined on " + description());
    }

    virtual TypeInfoPtr as_ptr() const
    {
        throw std::logic_error("Type variation as_ptr_type undefined on " + description());
    }

    virtual TypeInfoPtr as_ref() const
    {
        throw std::logic_error("Type variation as_ref_type undefined on " + description());
    }

    virtual TypeInfoPtr remove_all_const() const
    {
        throw std::logic_error("Type variation remove_all_const undefined on " + description());
    }

    virtual std::string description() const = 0;

    std::size_t hash_value() const
    {

        if (!has_cached_hash)
        {
            cached_hash = 0;
            boost::hash_combine(cached_hash, get_system());
            boost::hash_combine(cached_hash, calc_hash());
            has_cached_hash = true;
        }
        return cached_hash;
    }

    TypeIndex get_index() const;
};

inline std::size_t hash_value(AbstractTypeInfo const& info)
{
    return info.hash_value();
}

inline std::size_t hash_value(TypeInfoPtr info_p)
{
    return info_p->hash_value();
}

typedef AbstractTypeInfo::TypeInfoKey TypeInfoKey;

}}
