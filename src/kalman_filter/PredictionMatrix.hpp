#pragma once

#include <kalman_filter/EPredictionCell.hpp>

#include <cfloat>
#include <cmath>
#include <array>

namespace kalman_filter
{

class PredictionMatrix
{
public:
    void set(EPredictionCell cell, const float_t value);
    float_t get(EPredictionCell cell);
    
private:
    std::array<float_t, 4> prediction = { 0.0f, 0.0f, 0.0f, 0.0f };
};

} // kalman_filter
