#pragma once

#include <interface/SensorIfc.hpp>

#include <memory>
#include <string>

namespace interface
{
    class AccelerometerIfc;
    class GyroscopeIfc;
} // interface

namespace implementation
{
    
class Mpu6050 : 
    public interface::SensorIfc
{
public:
    Mpu6050(const uint32_t addr);
    virtual ~Mpu6050() = default;
    
    virtual void read() override;
    virtual std::string getRawData() override;
    virtual std::string getNormalizeData() override;
    
private:
    std::unique_ptr<interface::GyroscopeIfc> gyro;
    std::unique_ptr<interface::AccelerometerIfc> acc;
    int32_t fd;
};
    
} // implementation 
