#include <utils/GyroscopeNormalize.hpp>

namespace utils
{

GyroscopeNormalize::GyroscopeNormalize(const float_t scale) :
    scale(scale)
{
}

float_t GyroscopeNormalize::normalize(const float_t data)
{
    return data / scale;
}

} // utils
