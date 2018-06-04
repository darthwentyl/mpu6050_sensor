#include <implementation/Mpu6050.hpp>
#include <implementation/AccelerometerMpu6050.hpp>
#include <implementation/GyroscopeMpu6050.hpp>
#include <execption/Mpu6050NotFound.hpp>

#include <wiringPiI2C.h>
#include <iostream>
#include <stdexcept>

namespace implementation
{

using namespace execption;
    
Mpu6050::Mpu6050(const uint32_t addr) : 
    gyro(nullptr),
    acc(nullptr)
{
    fd =  wiringPiI2CSetup(addr);
    if(fd == -1)
    {
        throw Mpu6050NotFound(std::string("Device not found. Please check device I2C address"));
    }
    gyro = std::make_unique<GyroscopeMpu6050>(fd);
    acc = std::make_unique<AccelerometerMpu6050>(fd);
    wiringPiI2CWriteReg8(fd,0x6B,0x00);//disable sleep mode
}
    
void Mpu6050::read()
{
    try
    {
        acc->readData();
        gyro->readData();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<std::endl;
    }
}
    
void Mpu6050::print()
{
    try
    {
        acc->printData();
        gyro->printData();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
    
} // implementation
