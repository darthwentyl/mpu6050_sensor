#pragma once

#include <interface/KalmanFilterIfc.hpp>
#include <data_structure/OrientationData.hpp>
#include <kalman_filter/CalculationPitch.hpp>
#include <kalman_filter/CalculationRoll.hpp>

#include <string>
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
    virtual std::string get() override;

private:
    void updatePitch();
    void updateRoll();

    interface::AccelerometerIfc& acc;
    interface::GyroscopeIfc& gyro;
    CalculationPitch pitchCalc;
    CalculationRoll rollCalc;
    data_structure::OrientationData orientation;
};

} // kalman_filter
