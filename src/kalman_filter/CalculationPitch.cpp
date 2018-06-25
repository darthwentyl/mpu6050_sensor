#include <kalman_filter/CalculationPitch.hpp>

#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>

#include <iostream>

namespace kalman_filter
{

constexpr float_t DELTA_TIME = 0.1f;

using namespace data_structure;
using namespace interface;

CalculationPitch::CalculationPitch(AccelerometerIfc& acc, GyroscopeIfc& gyro) :
    acc(acc),
    gyro(gyro)
{
}

float_t CalculationPitch::calculate()
{
    AccelerometerData accData = acc.getConvertedData();
    GyroscopeData gyroData = gyro.getConvertedData();
    
    float_t accPitch = -(atan2f(accData.x, sqrt(accData.y * accData.y + accData.z * accData.z)) * 180.0f) / M_PI;
 
    return matrixOperation.get(accPitch, gyroData.y, DELTA_TIME);
}

} // kalman_filter
