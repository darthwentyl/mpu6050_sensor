#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <data_structure/AccelerometerData.hpp>
#include <data_structure/GyroscopeData.hpp>
#include <ser_des/SerDesOrientation.hpp>

namespace kalman_filter
{

using namespace ser_des;
using namespace data_structure;

KalmanFilterMpu6050::KalmanFilterMpu6050(data_structure::AccelerometerData& accData, data_structure::GyroscopeData& gyroData) :
    accData(accData),
    gyroData(gyroData),
    pitchCalc(accData, gyroData),
    rollCalc(accData, gyroData)
{}

void KalmanFilterMpu6050::update()
{
    updatePitch();
    updateRoll();
}

void KalmanFilterMpu6050::updatePitch()
{
    orientation.pitch = pitchCalc.calculate();
}

void KalmanFilterMpu6050::updateRoll()
{
    orientation.roll = rollCalc.calculate();
}

std::string KalmanFilterMpu6050::get()
{
    return SerDesOrientation::serialize(orientation);
}

} // kalman_filter
