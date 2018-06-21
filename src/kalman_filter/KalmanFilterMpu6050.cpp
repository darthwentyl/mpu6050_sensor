#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>

#include <iostream>

namespace kalman_filter
{

using namespace interface;

KalmanFilterMpu6050::KalmanFilterMpu6050(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro) :
    acc(acc),
    gyro(gyro),
    pitch(acc, gyro),
    roll(acc, gyro)
{}

void KalmanFilterMpu6050::update()
{
    updatePitch();
    updateRoll();
}

void KalmanFilterMpu6050::updatePitch()
{
    std::cout << "pitch = " << pitch.calculate() << std::endl;
    std::cout << "roll = " << roll.calculate() <<std::endl;
}

void KalmanFilterMpu6050::updateRoll()
{
}

} // kalman_filter
