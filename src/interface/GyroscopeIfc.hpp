#pragma once

#include <data_structure/GyroscopeData.hpp>

namespace interface
{
    
class GyroscopeIfc
{
public:
    virtual ~GyroscopeIfc() = default;
    
    virtual data_structure::GyroscopeData getData() = 0;
    virtual void printData() = 0;
    virtual void readData() = 0;
};
    
} // interface
