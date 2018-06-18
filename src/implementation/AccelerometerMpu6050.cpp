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
    AccelerometerHumanReadable humanReadable(SCALE);
    std::cout << "accelerometer x = " << humanReadable.convert(data.x) << "g" << std::endl;
    std::cout << "accelerometer y = " << humanReadable.convert(data.y) << "g" << std::endl;
    std::cout << "accelerometer z = " << humanReadable.convert(data.z) << "g" << std::endl;
}

void AccelerometerMpu6050::readData()
{
    data.x = static_cast<float_t>(readMpu6050Data(ACC_X_ADDR));
    data.y = static_cast<float_t>(readMpu6050Data(ACC_Y_ADDR));
    data.z = static_cast<float_t>(readMpu6050Data(ACC_Z_ADDR));
}

AccelerometerData AccelerometerMpu6050::getData() 
{
    return data;
}

} // implementation
