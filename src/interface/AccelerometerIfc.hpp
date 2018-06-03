#pragma once

#include <data_structure/AccelerometerData.hpp>

namespace interface
{

class AccelerometerIfc
{
public:
    virtual ~AccelerometerIfc() = default;
    
    virtual data_structure::AccelerometerData getData() = 0;
    virtual void printData() = 0;
    virtual void readData() = 0;
};

} // interface
