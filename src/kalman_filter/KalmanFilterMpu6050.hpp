#pragma once

#include <interface/KalmanFilterIfc.hpp>
#include <kalman_filter/PredictionMatrix.hpp>
#include <kalman_filter/KalmanAmplifierMatrix.hpp>
#include <kalman_filter/CovarianceMatrix.hpp>

#include <cfloat>
#include <cmath>

namespace interface
{
    class AccelerometerIfc;
    class GyroscopeIfc;
} // implementation

namespace kalman_filter
{

class KalmanFilterMpu6050 : public interface::KalmanFilterIfc
{
public:
    KalmanFilterMpu6050(interface::AccelerometerIfc& acc, interface::GyroscopeIfc& gyro);
    virtual ~KalmanFilterMpu6050() = default;

    virtual void update() override;

private:
    void updatePitch();
    void updateRoll();

    interface::AccelerometerIfc& acc;
    interface::GyroscopeIfc& gyro;
    
    PredictionMatrix prediction;
    KalmanAmplifierMatrix kalmanAmplifier;
    CovarianceMatrix covariance;
};

} // kalman_filter
