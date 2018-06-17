#pragma once

#include <cfloat>
#include <cmath>

namespace utils { namespace helpers {

struct GyroscopeDataF
{
    GyroscopeDataF() :
        x(0.0f),
        y(0.0f),
        z(0.0f)
    {}
    
    float_t x;
    float_t y;
    float_t z;
};

} } // utils::helpers
