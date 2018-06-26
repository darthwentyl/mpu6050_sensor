#include <kalman_filter/KalmanMatrixOperation.hpp>

#define CELL(x) static_cast<uint32_t>(ECovariance::x)

namespace kalman_filter
{

constexpr float_t CONF_ANGLE = 0.001f;
constexpr float_t CONF_BIAS = 0.003f;
constexpr float_t CONF_MEASUREMENT = 0.03f;

enum class ECovariance : uint32_t
{
    ANGLE = 0,
    BIAS = 1
};
    
KalmanMatrixOperation::KalmanMatrixOperation() :
    r(CONF_MEASUREMENT),
    s(0.0f),
    y(0.0f),
    K_rate(0.0f),
    K_angle(0.0f),
    K_bias(0.0f)
{
    Q[CELL(ANGLE)] = CONF_ANGLE;
    Q[CELL(BIAS)] = CONF_BIAS;
}

float_t KalmanMatrixOperation::get(const float_t newAngle, const float_t newRate, const float_t& dt)
{
    calcCovarianceErrorMatrix(newRate, dt);
    updateKalmanGainMatrix();
    updateCovarianceErrorMatrix(newAngle);    
    return K_angle;
}

void KalmanMatrixOperation::calcCovarianceErrorMatrix(const float_t newRate, const float_t dt)
{
    K_rate = newRate - K_bias;
    K_angle += dt * K_rate;
    
    P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q[CELL(ANGLE)]);
    P[0][1] -= dt * P[1][1];
    P[1][0] -= dt * P[1][1];
    P[1][1] += Q[CELL(BIAS)] * dt;
}

void KalmanMatrixOperation::updateCovarianceErrorMatrix(const float_t newAngle)
{
    y = newAngle - K_angle;
    
    K_angle += K[0] * y;
    K_bias += K[1] * y;
    
    float_t P00 = P[0][0];
    float_t P01 = P[0][1];
    
    P[0][0] -= K[0] * P00;
    P[0][1] -= K[0] * P01;
    P[1][0] -= K[1] * P00;
    P[1][1] -= K[1] * P01;
}

void KalmanMatrixOperation::updateKalmanGainMatrix()
{
    s = P[0][0] + r;
    
    K[0] = P[0][0] / s;
    K[1] = P[1][0] / s;
}

} // kalman_filter
