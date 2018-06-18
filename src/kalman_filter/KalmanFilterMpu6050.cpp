#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>

namespace kalman_filter
{

using namespace interface;

constexpr float_t DELTA_TIME = 1.0f;
constexpr float_t CONF_ANGLE = 0.001f;
constexpr float_t CONF_DEVATION = 0.003f;
constexpr float_t CONF_MEASUREMENT = 0.03f;

KalmanFilterMpu6050::KalmanFilterMpu6050(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro) :
    acc(acc),
    gyro(gyro)
{}

void KalmanFilterMpu6050::update()
{
}

} // kalman_filter
