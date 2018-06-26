#include <implementation/AccelerometerMpu6050.hpp>
#include <utils/AccelerometerNormalize.hpp>

#include <cfloat>
#include <cmath>

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

void AccelerometerMpu6050::readData()
{
    data.x = static_cast<float_t>(readMpu6050Data(ACC_X_ADDR));
    data.y = static_cast<float_t>(readMpu6050Data(ACC_Y_ADDR));
    data.z = static_cast<float_t>(readMpu6050Data(ACC_Z_ADDR));
}

AccelerometerData AccelerometerMpu6050::getRawData() 
{
    return data;
}

AccelerometerData AccelerometerMpu6050::getNormalizeData() 
{
    AccelerometerData convertedData;
    AccelerometerNormalize accNormalize(SCALE);
    convertedData.x = accNormalize.normalize(data.x);
    convertedData.y = accNormalize.normalize(data.y);
    convertedData.z = accNormalize.normalize(data.z);
    return convertedData;
}

} // implementation
