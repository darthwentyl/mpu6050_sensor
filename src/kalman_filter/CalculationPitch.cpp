#include <kalman_filter/CalculationPitch.hpp>
#include <kalman_filter/KalmanAmplifierMatrix.hpp>
#include <kalman_filter/EPredictionCell.hpp>
#include <kalman_filter/ECovarianceCell.hpp>
#include <interface/AccelerometerIfc.hpp>
#include <interface/GyroscopeIfc.hpp>
#include <data_structure/AccelerometerData.hpp>
#include <data_structure/GyroscopeData.hpp>

#include <iostream>

namespace kalman_filter
{

using namespace data_structure;
using namespace interface;

constexpr float_t CONF_ANGLE = 0.001f;
constexpr float_t CONF_BIAS = 0.003f;
constexpr float_t CONF_MEASUREMENT = 0.03f;

CalculationPitch::CalculationPitch(AccelerometerIfc& acc, GyroscopeIfc& gyro, const float_t& deltaTime) :
    acc(acc),
    gyro(gyro),
    covariance(CONF_ANGLE, CONF_BIAS),
    deltaTime(deltaTime),
    measurement(CONF_MEASUREMENT)
{}

float_t CalculationPitch::calculate()
{
    AccelerometerData accData = acc.getConvertedData();
    GyroscopeData gyroData = gyro.getConvertedData();
    
    float_t accPitch = -(atan2f(accData.x, sqrt(accData.y * accData.y + accData.z * accData.z) * 180.0f) / M_PI);
    std::cout << "accPitch " << accPitch << std::endl;
    kalmanAmplifier.set(EKalmanAmplifierCell::RATE, gyroData.y - kalmanAmplifier.get(EKalmanAmplifierCell::BIAS));
    
    float_t kalmanAngle = kalmanAmplifier.get(EKalmanAmplifierCell::RATE);
    kalmanAngle += deltaTime * kalmanAmplifier.get(EKalmanAmplifierCell::RATE);
    kalmanAmplifier.set(EKalmanAmplifierCell::ANGLE, kalmanAngle);
    
    float_t newPrediction00 = prediction.get(EPredictionCell::POS_0x0);
    newPrediction00 +=  deltaTime * (prediction.get(EPredictionCell::POS_1x1) + prediction.get(EPredictionCell::POS_0x1)) + covariance.get(ECovarianceCell::ANGLE) * deltaTime;
    prediction.set(EPredictionCell::POS_0x0, newPrediction00);
    
    float_t newPrediction01 = prediction.get(EPredictionCell::POS_0x1);
    newPrediction01 -= deltaTime * prediction.get(EPredictionCell::POS_1x1);
    prediction.set(EPredictionCell::POS_0x1, newPrediction01);
    
    float_t newPrediction10 = prediction.get(EPredictionCell::POS_1x0);
    newPrediction10 -= deltaTime * prediction.get(EPredictionCell::POS_1x1);
    prediction.set(EPredictionCell::POS_1x0, newPrediction10);
    
    float_t newPrediction11 = prediction.get(EPredictionCell::POS_1x1);
    newPrediction11 += covariance.get(ECovarianceCell::BIAS) * deltaTime;
    prediction.set(EPredictionCell::POS_1x1, newPrediction11);
    
    float_t S = prediction.get(EPredictionCell::POS_0x0) + measurement; // czym jest S???
    
    float_t newKalmanAmplifier0 = prediction.get(EPredictionCell::POS_0x0) / S;
    float_t newKalmanAmplifier1 = prediction.get(EPredictionCell::POS_1x0) / S;
    
    float_t newValue = accPitch - kalmanAmplifier.get(EKalmanAmplifierCell::ANGLE);
    
    float_t newKalmanAmplifierAngle = kalmanAmplifier.get(EKalmanAmplifierCell::ANGLE);
    newKalmanAmplifierAngle += newKalmanAmplifier0 * newValue;
    kalmanAmplifier.set(EKalmanAmplifierCell::ANGLE, newKalmanAmplifierAngle);
    
    float_t newKalmanAmplifierBias = kalmanAmplifier.get(EKalmanAmplifierCell::BIAS);
    newKalmanAmplifierBias += newKalmanAmplifier1 * newValue;
    kalmanAmplifier.set(EKalmanAmplifierCell::BIAS, newKalmanAmplifierBias);
    
    newPrediction00 = prediction.get(EPredictionCell::POS_0x0);
    newPrediction00 -=  newKalmanAmplifier0 * prediction.get(EPredictionCell::POS_0x0);
    prediction.set(EPredictionCell::POS_0x0, newPrediction00);
    
    newPrediction01 = prediction.get(EPredictionCell::POS_0x1);
    newPrediction01 -= newKalmanAmplifier0 * prediction.get(EPredictionCell::POS_0x1);
    prediction.set(EPredictionCell::POS_0x1, newPrediction01);
    
    newPrediction10 = prediction.get(EPredictionCell::POS_1x0);
    newPrediction10 -= newKalmanAmplifier1 * prediction.get(EPredictionCell::POS_1x0);;
    prediction.set(EPredictionCell::POS_1x0, newPrediction10);
    
    newPrediction11 = prediction.get(EPredictionCell::POS_1x1);
    newPrediction11 -= newKalmanAmplifier1 * prediction.get(EPredictionCell::POS_1x1);
    prediction.set(EPredictionCell::POS_1x1, newPrediction11);

    return kalmanAmplifier.get(EKalmanAmplifierCell::ANGLE);
}
} // kalman_filter
