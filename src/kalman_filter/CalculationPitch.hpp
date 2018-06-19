#pragma once

#include <kalman_filter/PredictionMatrix.hpp>
#include <kalman_filter/KalmanAmplifierMatrix.hpp>

#include <cfloat>
#include <cmath>

namespace data_structure
{
    class AccelerometerData;
    class GyroscopeData;

} // data_structure

namespace kalman_filter
{

    class PredictionMatrix;
    class KalmanAmplifierMatrix;

class CalculationPitch
{
public:
    CalculationPitch(data_structure::AccelerometerData& acc, data_structure::GyroscopeData& gyro, const float_t delta_time);
    float_t calculate();
    
private:
    data_structure::AccelerometerData& acc;
    data_structure::GyroscopeData& gyro;
    PredictionMatrix prediction;
    KalmanAmplifierMatrix kalmanAmplifier;
    const float_t deltaTime;
};

} // kalman_filter
