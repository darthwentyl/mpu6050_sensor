#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>
#include <kalman_filter/CalculationPitch.hpp>
#include <kalman_filter/CalculationRoll.hpp>

namespace kalman_filter
{

using namespace interface;

constexpr float_t DELTA_TIME = 0.1f;
constexpr float_t CONF_ANGLE = 0.001f;
constexpr float_t CONF_DEVATION = 0.003f;
constexpr float_t CONF_MEASUREMENT = 0.03f;

KalmanFilterMpu6050::KalmanFilterMpu6050(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro) :
    acc(acc),
    gyro(gyro),
    covariance(CONF_ANGLE, CONF_DEVATION)
{}

void KalmanFilterMpu6050::update()
{
    updatePitch();
    updateRoll();
}

void KalmanFilterMpu6050::updatePitch()
{
    
}

void KalmanFilterMpu6050::updateRoll()
{
}

} // kalman_filter
