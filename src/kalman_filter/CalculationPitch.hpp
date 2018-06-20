#pragma once

#include <kalman_filter/PredictionMatrix.hpp>
#include <kalman_filter/KalmanAmplifierMatrix.hpp>
#include <kalman_filter/CovarianceMatrix.hpp>

#include <cfloat>
#include <cmath>

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
    CalculationPitch(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro, const float_t& delta_time);
    float_t calculate();
    
private:
    interface::AccelerometerIfc& acc;
    interface::GyroscopeIfc& gyro;
    
    PredictionMatrix prediction;
    KalmanAmplifierMatrix kalmanAmplifier;
    CovarianceMatrix covariance;
    
    const float_t deltaTime;
    const float_t measurement;
};

} // kalman_filter
