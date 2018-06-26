#include <kalman_filter/CalculationPitch.hpp>

#include <data_structure/AccelerometerData.hpp>
#include <data_structure/GyroscopeData.hpp>

#include <iostream>

namespace kalman_filter
{

constexpr float_t DELTA_TIME = 0.1f;

using namespace data_structure;

CalculationPitch::CalculationPitch(AccelerometerData& accData, GyroscopeData& gyroData) :
    accData(accData),
    gyroData(gyroData)
{
}

float_t CalculationPitch::calculate()
{
    float_t accPitch = -(atan2f(accData.x, sqrt(accData.y * accData.y + accData.z * accData.z)) * 180.0f) / M_PI;
 
    return matrixOperation.get(accPitch, gyroData.y, DELTA_TIME);
}

} // kalman_filter
