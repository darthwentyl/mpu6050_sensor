#include <implementation/Mpu6050ReadData.hpp>

#include <execption/FileDescriptorExecption.hpp>

#include <limits>
#include <wiringPiI2C.h>

namespace implementation
{

using namespace exception;
    
Mpu6050I2CReadData::Mpu6050I2CReadData() :
    fd(-1)
{}

int32_t Mpu6050I2CReadData::readMpu6050Data(const int32_t addr)
{
    if(fd == -1)
    {
        throw FileDescriptorExecption("File descriptor is -1. Probably you don't  init it");
    }
    
    int32_t value = 0;
    value = wiringPiI2CReadReg8(fd, addr);
    value = value << 8;
    value += wiringPiI2CReadReg8(fd, addr+1);
    if (value >= 0x8000)
    {
        value = -(std::numeric_limits<uint16_t>::max() - value);
    }
    return value;    
}

void Mpu6050I2CReadData::init(const int32_t fd_)
{
    fd = fd_;
}

} // implementation
