#pragma once

#include <interface/SensorIfc.hpp>

#include <memory>

namespace interface
{
    class AccelerometerIfc;
    class GyroscopeIfc;
}

namespace implementation
{
    
class Mpu6050 : 
    public interface::SensorIfc
{
public:
    Mpu6050(const uint32_t addr);
    virtual ~Mpu6050() = default;
    
    virtual void read();
    virtual void print();
    
private:
    std::unique_ptr<interface::GyroscopeIfc> gyro;
    std::unique_ptr<interface::AccelerometerIfc> acc;
    int32_t fd;
};
    
} // implementation 
