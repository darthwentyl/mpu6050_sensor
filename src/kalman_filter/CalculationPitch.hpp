#pragma once

#include <array>
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

    std::array<std::array<float_t, 2>, 2> P = {0.0f, 0.0f, 0.0f, 0.0f}; // covariance error matrix
    std::array<float_t, 2> K = {0.0f, 0.0f}; // kalman gain matrix
    std::array<float_t, 2> Q = {0.0f, 0.0f}; // tuned matrix
    
    const float_t dt;
    float_t r; // raw measure
    float_t s; // estimate error
    float_t y; // angle difference
    float_t K_rate;
    float_t K_angle;
    float_t K_bias;
};

} // kalman_filter
