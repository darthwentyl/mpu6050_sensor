#pragma once

#include <interface/GyroscopeIfc.hpp>
#include <implementation/Mpu6050ReadData.hpp>
#include <data_structure/GyroscopeData.hpp>

namespace implementation
{
    
class GyroscopeMpu6050 :
    public interface::GyroscopeIfc,
    public Mpu6050I2CReadData
{
public:
    GyroscopeMpu6050(const int32_t fd);
    virtual ~GyroscopeMpu6050() = default;
    
    virtual void printData() override;
    virtual void printHumanReadableData() override;
    virtual void readData() override;
    virtual data_structure::GyroscopeData getData() override;
    
private:
    data_structure::GyroscopeData data;
};
    
} // implementation
