#pragma once

#include <kalman_filter/EKalmanAmplifierCell.hpp>

#include <cfloat>
#include <cmath>
#include <array>

namespace kalman_filter
{

class KalmanAmplifierMatrix 
{
public:
    void set(EKalmanAmplifierCell cell, float_t value);
    float_t get(EKalmanAmplifierCell cell);
    
private:
    std::array<float_t, 3> kalmanAmplifier = {0.0f, 0.0f, 0.0f};
};

} // kalman_filter
