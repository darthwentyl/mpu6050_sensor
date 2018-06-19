#include <kalman_filter/PredictionMatrix.hpp>
#include <cstdint>

namespace kalman_filter
{

void PredictionMatrix::set(EPredictionCell cell, const float_t value)
{
    prediction[static_cast<uint32_t>(cell)] = value;
}

float_t PredictionMatrix::get(EPredictionCell cell)
{
    return prediction[static_cast<uint32_t>(cell)];
}


} // kalman_filter
