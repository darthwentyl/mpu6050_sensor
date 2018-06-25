#pragma once

#include <kalman_filter/KalmanMatrixOperation.hpp>

namespace interface
{
    class AccelerometerIfc;
    class GyroscopeIfc;

} // data_structure

namespace kalman_filter
{

class CalculationPitch
{
public:
    CalculationPitch(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro);
    float_t calculate();
    
private:
    interface::AccelerometerIfc& acc;
    interface::GyroscopeIfc& gyro;
    
    KalmanMatrixOperation matrixOperation;
    float_t pitch;
};

} // kalman_filter
