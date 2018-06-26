#include <implementation/GyroscopeMpu6050.hpp>
#include <utils/GyroscopeNormalize.hpp>

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

GyroscopeData GyroscopeMpu6050::getNormalizeData()
{
    GyroscopeData convertedData;
    GyroscopeNormalize gyroNormalize(SCALE);
    convertedData.x = gyroNormalize.normalize(data.x);
    convertedData.y = gyroNormalize.normalize(data.y);
    convertedData.z = gyroNormalize.normalize(data.z);
    return convertedData;
}

} // implementation
