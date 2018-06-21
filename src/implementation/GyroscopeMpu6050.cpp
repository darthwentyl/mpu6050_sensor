#include <implementation/GyroscopeMpu6050.hpp>
#include <utils/GyroscopeHumanReadable.hpp>

#include <iostream>

namespace implementation
{

using namespace data_structure;
using namespace utils;

constexpr int32_t GYRO_X_ADDR = 0x43;
constexpr int32_t GYRO_Y_ADDR = 0x45;
constexpr int32_t GYRO_Z_ADDR = 0x47;
constexpr float_t SCALE = 131.064f;

GyroscopeMpu6050::GyroscopeMpu6050(const int32_t fd)
{
    init(fd);
}

void GyroscopeMpu6050::printRawData()
{
    std::cout << "gyroscope x(" << data.x << ")" << std::endl;
    std::cout << "gyroscope y(" << data.y << ")" << std::endl;
    std::cout << "gyroscope z(" << data.z << ")" << std::endl;
}

void GyroscopeMpu6050::printHumanReadableData()
{
    GyroscopeHumanReadable humanReadable(SCALE);
    std::cout << "gyroscope x = " << humanReadable.convert(data.x) << " degree/sec" << std::endl;
    std::cout << "gyroscope y = " << humanReadable.convert(data.y) << " degree/sec" << std::endl;
    std::cout << "gyroscope z = " << humanReadable.convert(data.z) << " degree/sec" << std::endl;
}

void GyroscopeMpu6050::readData()
{
    data.x = static_cast<float_t>(readMpu6050Data(GYRO_X_ADDR));
    data.y = static_cast<float_t>(readMpu6050Data(GYRO_Y_ADDR));
    data.z = static_cast<float_t>(readMpu6050Data(GYRO_Z_ADDR));
}

GyroscopeData GyroscopeMpu6050::getRawData()
{
    return data;
}

GyroscopeData GyroscopeMpu6050::getConvertedData()
{
    GyroscopeData convertedData;
    GyroscopeHumanReadable humanReadable(SCALE);
    convertedData.x = humanReadable.convert(data.x);
    convertedData.y = humanReadable.convert(data.y);
    convertedData.z = humanReadable.convert(data.z);
    return convertedData;
}

} // implementation
