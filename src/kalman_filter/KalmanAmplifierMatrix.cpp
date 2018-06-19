#include <kalman_filter/KalmanAmplifierMatrix.hpp>

#include <cstdint>

namespace kalman_filter
{

void KalmanAmplifierMatrix::set(EKalmanAmplifierCell cell, float_t value)
{
    kalmanAmplifier[static_cast<uint32_t>(cell)] = value;
}

float_t KalmanAmplifierMatrix::get(EKalmanAmplifierCell cell)
{
    return kalmanAmplifier[static_cast<uint32_t>(cell)];
}

} // kalman_filter
