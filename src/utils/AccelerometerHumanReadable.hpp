#pragma once

#include <cstdint>
#include <cfloat>
#include <cmath>

namespace utils
{

class AccelerometerHumanReadable
{
public:
    AccelerometerHumanReadable(const float_t scale);
    
    float_t convert(const int32_t data);
    
private:
    float_t scale;
};

} // utils
