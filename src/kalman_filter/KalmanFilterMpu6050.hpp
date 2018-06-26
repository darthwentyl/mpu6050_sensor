#pragma once

#include <interface/KalmanFilterIfc.hpp>
#include <data_structure/OrientationData.hpp>
#include <kalman_filter/CalculationPitch.hpp>
#include <kalman_filter/CalculationRoll.hpp>

#include <string>
#include <cfloat>
#include <cmath>

namespace data_structure
{
    class AccelerometerData;
    class GyroscopeData;
} // data_structure

namespace kalman_filter
{

class KalmanFilterMpu6050 : public interface::KalmanFilterIfc
{
public:
    KalmanFilterMpu6050(data_structure::AccelerometerData& accData, data_structure::GyroscopeData& gyroData);
    virtual ~KalmanFilterMpu6050() = default;

    virtual void update() override;
    virtual std::string get() override;

private:
    void updatePitch();
    void updateRoll();

    data_structure::AccelerometerData& accData;
    data_structure::GyroscopeData& gyroData;
    CalculationPitch pitchCalc;
    CalculationRoll rollCalc;
    data_structure::OrientationData orientation;
};

} // kalman_filter
