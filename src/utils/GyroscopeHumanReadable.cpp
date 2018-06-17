#include <utils/GyroscopeHumanReadable.hpp>

namespace utils
{

using namespace helpers;

GyroscopeHumanReadable::GyroscopeHumanReadable(const data_structure::GyroscopeData& data_, const float_t scale) :
    scale(scale)
{
    data.x = float_t(data_.x) / scale;
    data.y = float_t(data_.y) / scale;
    data.z = float_t(data_.z) / scale;
}

float_t GyroscopeHumanReadable::convertXRotation()
{
    return distance(data.x, data.z);
}

float_t GyroscopeHumanReadable::convertYRotation()
{
    return distance(data.y, data.z);
}

float_t GyroscopeHumanReadable::distance(const int32_t a, const int32_t b)
{
    return sqrt(float_t(a*a) + float_t(b*b));
}

float_t GyroscopeHumanReadable::radToDegree(const float_t angle)
{
    return (angle * 180) / M_PI;
}

} // utils
