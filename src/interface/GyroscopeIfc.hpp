#pragma once

#include <data_structure/GyroscopeIfc.hpp>

namespace interface
{
    
class GyroscopeIfc
{
public:
    virtual ~GyroscopeData() = default;
    
    virtual data_structure::GyroscopeData getData() = 0;
    virtual void print() = 0;
    virtual void read() = 0;
};
    
} // interface
