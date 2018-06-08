#include <implementation/AccelerometerMpu6050.hpp>
#include <utils/AccelerometerHumanReadable.hpp>

#include <cfloat>
#include <cmath>
#include <iostream>

namespace implementation
{

using namespace data_structure;
using namespace utils;

constexpr int32_t ACC_X_ADDR = 0x3B;
constexpr int32_t ACC_Y_ADDR = 0x3D;
constexpr int32_t ACC_Z_ADDR = 0x3F;

constexpr float_t SCALE = 16384.0f;

AccelerometerMpu6050::AccelerometerMpu6050(const int32_t fd)
{
    init(fd);
}

void AccelerometerMpu6050::printData()
{
    std::cout << "accelerometer x(" << data.x << ")" << std::endl;
    std::cout << "accelerometer y(" << data.y << ")" << std::endl;
    std::cout << "accelerometer z(" << data.z << ")" << std::endl;
}

void AccelerometerMpu6050::printHumanReadableData()
{
    std::cout << "accelerometer x = " << AccelerometerHumanReadable::convert(data.x, SCALE) << "g" << std::endl;
    std::cout << "accelerometer y = " << AccelerometerHumanReadable::convert(data.y, SCALE) << "g" << std::endl;
    std::cout << "accelerometer z = " << AccelerometerHumanReadable::convert(data.z, SCALE) << "g" << std::endl;
}

void AccelerometerMpu6050::readData()
{
    data.x = readMpu6050Data(ACC_X_ADDR);
    data.y = readMpu6050Data(ACC_Y_ADDR);
    data.z = readMpu6050Data(ACC_Z_ADDR);
}

AccelerometerData AccelerometerMpu6050::getData() 
{
    return data;
}

} // implementation
