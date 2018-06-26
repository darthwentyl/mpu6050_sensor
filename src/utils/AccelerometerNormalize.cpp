#include <utils/AccelerometerNormalize.hpp>

namespace utils
{

AccelerometerNormalize::AccelerometerNormalize(const float_t scale) :
    scale(scale)
{}


float_t AccelerometerNormalize::normalize(const float_t data)
{
    return data / scale;
}

} // utils
