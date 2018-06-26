#pragma once

#include <data_structure/AccelerometerData.hpp>
#include <data_structure/GyroscopeData.hpp>

namespace data_structure
{

struct Mpu6050Data
{
    AccelerometerData acc;
    GyroscopeData gyro;
};

} // data_structure
