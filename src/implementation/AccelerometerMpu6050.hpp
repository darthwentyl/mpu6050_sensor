#pragma once

#include <interface/AccelerometerIfc.hpp>
#include <data_structure/AccelerometerData.hpp>
#include <implementation/Mpu6050ReadData.hpp>

namespace implementation
{
    
class AccelerometerMpu6050 :
    public interface::AccelerometerIfc,
    public Mpu6050I2CReadData
{
public:
    AccelerometerMpu6050(const int32_t fd);
    virtual ~AccelerometerMpu6050() = default;

    virtual void printData();
    virtual void readData();
    virtual data_structure::AccelerometerData getData(); 

private:
    data_structure::AccelerometerData data;
};
    
} // implementation 
