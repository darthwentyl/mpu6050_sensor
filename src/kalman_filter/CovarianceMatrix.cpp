#include <kalman_filter/CovarianceMatrix.hpp>

#include <cstdint>

namespace kalman_filter
{

CovarianceMatrix::CovarianceMatrix(const float_t angle, const float_t bias)
{
    covariance[ECovarianceCell::ANGLE] = angle;
    covariance[ECovarianceCell::BIAS] = bias;
}

void CovarianceMatrix::set(ECovarianceCell cell, float_t value)
{
    covariance[static_cast<uint32_t>(cell)] = value;
}

float_t CovarianceMatrix::get(ECovarianceCell cell)
{
    return covariance[static_cast<uint32_t>(cell)];
}
    
} // kalman_filter
