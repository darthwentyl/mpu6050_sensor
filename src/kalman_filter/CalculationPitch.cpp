#include <kalman_filter/CalculationPitch.hpp>
#include <kalman_filter/KalmanAmplifierMatrix.hpp>
#include <kalman_filter/EPredictionCell.hpp>
#include <data_structure/AccelerometerData.hpp>
#include <data_structure/GyroscopeData.hpp>

namespace kalman_filter
{

using namespace data_structure;

CalculationPitch::CalculationPitch(AccelerometerData& acc, GyroscopeData& gyro, const float_t deltaTime) :
    acc(acc),
    gyro(gyro),
    deltaTime(deltaTime)
{}

float_t CalculationPitch::calculate()
{
    float_t pitch = 0.0f;
    float_t accPitch = -(atan2f(acc.x, sqrt(acc.y * acc.y + acc.z * acc.z) * 180.0f) / M_PI);
    kalmanAmplifier.set(EKalmanAmplifierCell::RATE, accPitch - kalmanAmplifier.get(EKalmanAmplifierCell::BIAS));
    kalmanAmplifier.set(EKalmanAmplifierCell::ANGLE, deltaTime * kalmanAmplifier.get(EKalmanAmplifierCell::RATE));
    //prediction.get(EPredictionCell::POS_0x0) += prediction.set(deltaTime * (prediction.get(EPredictionCell::POS_1x1 +  
    return pitch;
}
} // kalman_filter
