#include <kalman_filter/CalculationRoll.hpp>
#include <data_structure/AccelerometerData.hpp>
#include <data_structure/GyroscopeData.hpp>

#include <iostream>

namespace kalman_filter
{

constexpr float_t DELTA_TIME = 0.1f;

using namespace data_structure;

CalculationRoll::CalculationRoll(AccelerometerData& accData, GyroscopeData& gyroData) :
    accData(accData),
    gyroData(gyroData)
{
}

float_t CalculationRoll::calculate()
{
    float_t accRoll = ((atan2f(accData.y, accData.z)) * 180.0f) / M_PI;
    return matrixOperation.get(accRoll, gyroData.x, DELTA_TIME);
}

} // kalman_filter
