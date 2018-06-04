#pragma once

#include <stdint.h>

namespace data_structure
{
    
struct AccelerometerData
{
    AccelerometerData() :
        x(0),
        y(0),
        z(0)
    {}
    
    int32_t x;
    int32_t y;
    int32_t z;
};
    
} // data_structure
