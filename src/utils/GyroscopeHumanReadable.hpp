#pragma once

#include <cstdint>
#include <cfloat>
#include <cmath>

namespace utils
{

class GyroscopeHumanReadable
{
public:
    GyroscopeHumanReadable(const float_t scale);
    float_t convert(const int32_t data);

private:
    float_t radToDegree(const float_t angle);

    int32_t scale;
};

} // utils
