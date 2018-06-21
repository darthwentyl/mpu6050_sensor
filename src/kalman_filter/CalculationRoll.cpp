#include <kalman_filter/CalculationRoll.hpp>
#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>

#include <iostream>

namespace kalman_filter
{

constexpr float_t DELTA_TIME = 0.1f;

using namespace data_structure;
using namespace interface;

CalculationRoll::CalculationRoll(AccelerometerIfc& acc, GyroscopeIfc& gyro) :
    acc(acc),
    gyro(gyro)
{
}

float_t CalculationRoll::calculate()
{
    AccelerometerData accData = acc.getConvertedData();
    GyroscopeData gyroData = gyro.getConvertedData();
    
    float_t accRoll = ((atan2f(accData.y, accData.z)) * 180.0f) / M_PI;
 
    return matrixOperation.get(accRoll, gyroData.x, DELTA_TIME);
}

} // kalman_filter
