#pragma once

#include <data_structure/Mpu6050Data.hpp>
#include <data_structure/OrientationData.hpp>

namespace utils
{

class PrintMpu6050Data
{
public:
    void printRawData(const data_structure::Mpu6050Data& data);
    void printNormalizeData(const data_structure::Mpu6050Data& data);
    void printOrientation(const data_structure::OrientationData& data);
};

} // utils
