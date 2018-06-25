#include <implementation/Mpu6050.hpp>
#include <implementation/AccelerometerMpu6050.hpp>
#include <implementation/GyroscopeMpu6050.hpp>
#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <exception/Mpu6050NotFoundException.hpp>
#include <data_structure/OrientationData.hpp>
#include <ser_des/SerDesOrientation.hpp>

#include <wiringPiI2C.h>
#include <iostream>
#include <stdexcept>

namespace implementation
{

using namespace exception;
using namespace kalman_filter;
using namespace data_structure;
using namespace ser_des;

Mpu6050::Mpu6050(const uint32_t addr) : 
    gyro(nullptr),
    acc(nullptr),
    kalman(nullptr)
{
    fd =  wiringPiI2CSetup(addr);
    if(fd == -1)
    {
        throw Mpu6050NotFoundException(std::string("Device not found. Please check device I2C address"));
    }
    gyro = std::make_unique<GyroscopeMpu6050>(fd);
    acc = std::make_unique<AccelerometerMpu6050>(fd);
    kalman = std::make_unique<KalmanFilterMpu6050>(*acc.get(), *gyro.get());
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
    
void Mpu6050::printRaw()
{
    try
    {
        acc->printRawData();
        gyro->printRawData();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Mpu6050::printHumanReadable()
{
    try
    {
        acc->printHumanReadableData();
        gyro->printHumanReadableData();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Mpu6050::printKalman()
{
    OrientationData orientation;
    kalman->update();
    orientation = SerDesOrientation::deserialize(kalman->get());
    std::cout << "deserialize pitch: " << orientation.pitch << " deserialize roll: " << orientation.roll << std::endl;
}
    
} // implementation
