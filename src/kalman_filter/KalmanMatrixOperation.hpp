#pragma once

#include <array>
#include <cfloat>
#include <cmath>

namespace kalman_filter
{

class KalmanMatrixOperation
{
public:
    KalmanMatrixOperation();
    
    float_t get(const float_t newAngle, const float_t newRate, const float_t& dt);
    
private:
    void calcCovarianceErrorMatrix(const float_t newRate, const float_t dt);
    void updateCovarianceErrorMatrix(const float_t newAngle);
    void updateKalmanGainMatrix();
    
    std::array<std::array<float_t, 2>, 2> P = {0.0f, 0.0f, 0.0f, 0.0f}; // covariance error matrix
    std::array<float_t, 2> K = {0.0f, 0.0f}; // kalman gain matrix
    std::array<float_t, 2> Q = {0.0f, 0.0f}; // tuned matrix

    float_t r; // raw measure
    float_t s; // estimate error
    float_t y; // angle difference
    float_t K_rate;
    float_t K_angle;
    float_t K_bias;
};

} // kalman_filter
