#include <utils/GyroscopeHumanReadable.hpp>

namespace utils
{

GyroscopeHumanReadable::GyroscopeHumanReadable(const float_t scale) :
    scale(scale)
{
}

float_t GyroscopeHumanReadable::convert(const int32_t data)
{
    return float_t(data) / scale;
}

} // utils
