#pragma once

#include <data_structure/GyroscopeData.hpp>
#include <utils/helpers/GyroscopeDataF.hpp>

#include <cstdint>
#include <cfloat>
#include <cmath>

namespace utils
{

class GyroscopeHumanReadable
{
public:
    GyroscopeHumanReadable(const data_structure::GyroscopeData& data_, const float_t scale);
    float_t convertXRotation();
    float_t convertYRotation();
    
private:
    float_t distance(const int32_t a, const int32_t b);
    float_t radToDegree(const float_t angle);
    
    helpers::GyroscopeDataF data;
    int32_t scale;
};

} // utils
