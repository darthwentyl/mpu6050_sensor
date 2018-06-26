#pragma once

#include <data_structure/Mpu6050Data.hpp>

#include <string>

namespace ser_des
{

class SerDesMpu6050Data
{
public:
    static std::string serialize(const data_structure::Mpu6050Data& data);
    static data_structure::Mpu6050Data deserialize(const std::string& data);
};

} // ser_des
