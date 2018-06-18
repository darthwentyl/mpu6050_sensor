#include <utils/GyroscopeHumanReadable.hpp>

namespace utils
{

GyroscopeHumanReadable::GyroscopeHumanReadable(const float_t scale) :
    scale(scale)
{
}

float_t GyroscopeHumanReadable::convert(const float_t data)
{
    return data / scale;
}

} // utils
