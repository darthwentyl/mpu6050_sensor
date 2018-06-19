#pragma once

#include <kalman_filter/ECovarianceCell.hpp>

#include <cfloat>
#include <cmath>
#include <array>

namespace kalman_filter
{

class CovarianceMatrix
{
public:
    CovarianceMatrix(const float_t angle, const float_t bias);
    
    void set(ECovarianceCell cell, float_t value);
    float_t get(ECovarianceCell cell);

private:
    std::array<float_t, 2> covariance;
};

} // kalman_filter
