#include <utils/AccelerometerHumanReadable.hpp>

namespace utils
{

AccelerometerHumanReadable::AccelerometerHumanReadable(const float_t scale) :
    scale(scale)
{}


float_t AccelerometerHumanReadable::convert(const float_t data)
{
    return data / scale;
}

} // utils
