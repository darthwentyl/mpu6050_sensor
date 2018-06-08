#pragma once

#include <cstdint>
#include <cfloat>
#include <cmath>

namespace utils
{

class AccelerometerHumanReadable
{
public:
    static float_t convert(const int32_t data, const float_t scale);
};

} // utils
