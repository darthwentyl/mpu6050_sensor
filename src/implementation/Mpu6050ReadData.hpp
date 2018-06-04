#pragma once

#include <stdint.h>

namespace implementation
{
    
class Mpu6050I2CReadData
{
public:
    Mpu6050I2CReadData();
    virtual ~Mpu6050I2CReadData() = default;
    
    int32_t readMpu6050Data(const int32_t addr);
    void init(const int32_t fd_);
    
private:
    int32_t fd;
};
    
} // implementation
