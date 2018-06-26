#pragma once

#include <kalman_filter/KalmanMatrixOperation.hpp>

namespace data_structure
{
    class AccelerometerData;
    class GyroscopeData;

} // data_structure

namespace kalman_filter
{

class CalculationRoll
{
public:
    CalculationRoll(data_structure::AccelerometerData& accData, data_structure::GyroscopeData& gyroData);
    float_t calculate();
    
private:
    data_structure::AccelerometerData& accData;
    data_structure::GyroscopeData& gyroData;
    
    KalmanMatrixOperation matrixOperation;
};

} // kalman_filter 
