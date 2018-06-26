#pragma once

#include <cfloat>
#include <cmath>

namespace utils
{

class GyroscopeNormalize
{
public:
    GyroscopeNormalize(const float_t scale);
    float_t normalize(const float_t data);

private:
    float_t scale;
};

} // utils
