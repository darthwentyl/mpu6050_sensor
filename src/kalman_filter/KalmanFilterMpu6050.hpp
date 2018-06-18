#pragma once

#include <interface/KalmanFilterIfc.hpp>

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
    interface::AccelerometerIfc& acc;
    interface::GyroscopeIfc& gyro;
};

} // kalman_filter
