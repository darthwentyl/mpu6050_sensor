#include <implementation/GyroscopeMpu6050.hpp>

#include <iostream>

namespace implementation
{

using namespace data_structure;

constexpr int32_t GYRO_X_ADDR = 0x43;
constexpr int32_t GYRO_Y_ADDR = 0x45;
constexpr int32_t GYRO_Z_ADDR = 0x47;

GyroscopeMpu6050::GyroscopeMpu6050(const int32_t fd)
{
    init(fd);
}

void GyroscopeMpu6050::printData()
{
    std::cout << "gyroscop x(" << data.x << ")" << std::endl;
    std::cout << "gyroscop y(" << data.y << ")" << std::endl;
    std::cout << "gyroscop z(" << data.z << ")" << std::endl;
}

void GyroscopeMpu6050::printHumanReadableData()
{
}

void GyroscopeMpu6050::readData()
{
    data.x = readMpu6050Data(GYRO_X_ADDR);
    data.y = readMpu6050Data(GYRO_Y_ADDR);
    data.z = readMpu6050Data(GYRO_Z_ADDR);
}

GyroscopeData GyroscopeMpu6050::getData()
{
    return data;
}    

} // implementation
