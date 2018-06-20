#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>

#include <iostream>

namespace kalman_filter
{

using namespace interface;

constexpr float_t DELTA_TIME = 0.1f;
//constexpr float_t CONF_ANGLE = 0.001f;
//constexpr float_t CONF_BIAS = 0.003f;
//constexpr float_t CONF_MEASUREMENT = 0.03f;

KalmanFilterMpu6050::KalmanFilterMpu6050(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro) :
    acc(acc),
    gyro(gyro),
    pitch(acc, gyro, DELTA_TIME)
//    roll(acc, gyro, DELTA_TIME)
{}

void KalmanFilterMpu6050::update()
{
    updatePitch();
    updateRoll();
}

void KalmanFilterMpu6050::updatePitch()
{
    std::cout << "pitch = " << pitch.calculate() << std::endl;
}

void KalmanFilterMpu6050::updateRoll()
{
}

} // kalman_filter
