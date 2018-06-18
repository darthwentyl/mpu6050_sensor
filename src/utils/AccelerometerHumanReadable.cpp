#include <utils/AccelerometerHumanReadable.hpp>

namespace utils
{

AccelerometerHumanReadable::AccelerometerHumanReadable(const float_t scale) :
    scale(scale)
{}


float_t AccelerometerHumanReadable::convert(const int32_t data)
{
    return float_t(data) / scale;
}

} // utils
