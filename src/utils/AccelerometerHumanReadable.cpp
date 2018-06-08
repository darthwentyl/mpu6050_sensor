#include <utils/AccelerometerHumanReadable.hpp>

namespace utils
{

float_t AccelerometerHumanReadable::convert(const int32_t data, const float_t scale)
{
    float_t retVal = float_t(data) / scale;
    return retVal;
}

} // utils
