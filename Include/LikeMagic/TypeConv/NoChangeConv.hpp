#pragma once

#include "ConvertibleTo.hpp"
#include "../SFMO/Trampoline.hpp"

namespace LikeMagic { namespace TypeConv {

using namespace LikeMagic::SFMO;

// The difference between implicit conv and no change conv
// is implicit conversion wraps the expression in a trampoline and
// returns the wrapped value unchanged, whereas no change conv
// doesn't even do that much - there's no trampoline, it simply
// asserts that the expression itself is a different expression.

class NoChangeConv : public AbstractTypeConverter
{
public:

    virtual ExprPtr wrap_expr(ExprPtr expr) const
    {
        return expr;
    }

    virtual std::string describe() const { return "NoChangeConv"; }
};

}}
