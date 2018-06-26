#pragma once

#include <kalman_filter/KalmanMatrixOperation.hpp>

namespace data_structure
{
    class AccelerometerData;
    class GyroscopeData;

} // data_structure

namespace kalman_filter
{

class CalculationPitch
{
public:
    CalculationPitch(data_structure::AccelerometerData& accData, data_structure::GyroscopeData& gyroData);
    float_t calculate();
    
private:
    data_structure::AccelerometerData& accData;
    data_structure::GyroscopeData& gyroData;
    
    KalmanMatrixOperation matrixOperation;
    float_t pitch;
};

} // kalman_filter
