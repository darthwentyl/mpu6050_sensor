#pragma once

#include <cfloat>
#include <cmath>

namespace data_structure
{
    
struct AccelerometerData
{
    AccelerometerData() :
        x(0.0f),
        y(0.0f),
        z(0.0f)
    {}
    
    float_t x;
    float_t y;
    float_t z;
};
    
} // data_structure
