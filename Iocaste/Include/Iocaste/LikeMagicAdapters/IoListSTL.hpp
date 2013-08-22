// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)


#include "IoList.h"
#include "List.h"

#include "Iocaste/LikeMagicAdapters/API_Io_Impl.hpp"
#include "LikeMagic/Exprs/Term.hpp"
#include "LikeMagic/Exprs/NullExpr.hpp"
#include "Iocaste/LikeMagicAdapters/IoBlock.hpp"

#include <iterator>

namespace Iocaste { namespace LMAdapters {

template <typename T> struct IoListElemConv;
template <> struct IoListElemConv<double> { static double do_conv(IoNumber* obj) { return IoNumber_asDouble(obj); }};

// Wraps an Io List as an STL-compliant C++ container
template <typename T>
class IoListSTL
{
private:
    List* list;

public:
    class const_iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    private:
        List* list;
        size_t pos;

    public:
        const_iterator(List* list_, size_t pos_=0)
            : list(list_), pos(pos_) {}

        T operator*() const
        {
            return IoListElemConv<T>::do_conv(reinterpret_cast<IoNumber*>(List_at_(list, pos)));
        }

        size_t operator -(const_iterator other) const { return this->pos - other.pos; }
        size_t operator --() { return --pos; }

        size_t operator +(const_iterator other) const { return this->pos + other.pos; }
        size_t operator ++() { return ++pos; }

    };

    IoListSTL(IoObject* self) : list(IoList_rawList(self)) { }

    const_iterator begin() const
    {
        return const_iterator(list);
    }

    const_iterator end() const
    {
        return const_iterator(list, size());
    }

    size_t size() const
    {
        return List_size(list);
    }

};

}}
