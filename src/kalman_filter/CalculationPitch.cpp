#include <kalman_filter/CalculationPitch.hpp>

#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>

#include <iostream>

#define CELL(x) static_cast<uint32_t>(ECovariance::x)

namespace kalman_filter
{

using namespace data_structure;
using namespace interface;

constexpr float_t CONF_ANGLE = 0.001f;
constexpr float_t CONF_BIAS = 0.003f;
constexpr float_t CONF_MEASUREMENT = 0.03f;

enum class ECovariance : uint32_t
{
    ANGLE = 0,
    BIAS = 1
};

CalculationPitch::CalculationPitch(AccelerometerIfc& acc, GyroscopeIfc& gyro, const float_t& deltaTime) :
    acc(acc),
    gyro(gyro),
    dt(deltaTime),
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

float_t CalculationPitch::calculate()
{
    AccelerometerData accData = acc.getConvertedData();
    GyroscopeData gyroData = gyro.getConvertedData();
    
    float_t accPitch = -(atan2f(accData.x, sqrt(accData.y * accData.y + accData.z * accData.z)) * 180.0f) / M_PI;
 
    K_rate = gyroData.y - K_bias;
    K_angle += dt * K_rate;
    
    P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q[CELL(ANGLE)]);
    P[0][1] -= dt * P[1][1];
    P[1][0] -= dt * P[1][1];
    P[1][1] += Q[CELL(BIAS)] * dt;
    
    s = P[0][0] + r;
    
    K[0] = P[0][0] / s;
    K[1] = P[1][0] / s;
    
    y = accPitch - K_angle;
    
    K_angle += K[0] * y;
    K_bias += K[1] * y;
    
    float_t P00 = P[0][0];
    float_t P01 = P[0][1];
    
    P[0][0] -= K[0] * P00;
    P[0][1] -= K[0] * P01;
    P[1][0] -= K[1] * P00;
    P[1][1] -= K[1] * P01;
    
    return K_angle;
}
} // kalman_filter
