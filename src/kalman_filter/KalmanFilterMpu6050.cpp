#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>
#include <ser_des/SerDesOrientation.hpp>

#include <iostream>

namespace kalman_filter
{

using namespace interface;
using namespace ser_des;
using namespace data_structure;

KalmanFilterMpu6050::KalmanFilterMpu6050(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro) :
    acc(acc),
    gyro(gyro),
    pitchCalc(acc, gyro),
    rollCalc(acc, gyro)
{}

void KalmanFilterMpu6050::update()
{
    updatePitch();
    updateRoll();
}

void KalmanFilterMpu6050::updatePitch()
{
    orientation.pitch = pitchCalc.calculate();
    std::cout << "pitch = " << orientation.pitch << std::endl;
}

void KalmanFilterMpu6050::updateRoll()
{
    orientation.roll = rollCalc.calculate();
    std::cout << "roll = " << orientation.roll <<std::endl;
}

std::string KalmanFilterMpu6050::get()
{
    return SerDesOrientation::serialize(orientation);
}

} // kalman_filter
