#pragma once

#include "AbstractInput.hpp"

#include <string>
#include <iostream>

namespace IoDbg {

class LineInput :
    public AbstractInput<std::string>
{
private:
    std::istream& stream;

public:
    LineInput(std::istream& stream_);
    virtual bool HasData() const;
    virtual std::string ReadData();
};

}

