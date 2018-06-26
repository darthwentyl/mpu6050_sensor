#include <ser_des/SerDesMpu6050Data.hpp>

#include <sstream>

namespace ser_des
{

using namespace data_structure;
    
std::string SerDesMpu6050Data::serialize(const data_structure::Mpu6050Data& data)
{
    std::stringstream ss;
    ss << data.acc.x << " " << data.acc.y << " " << data.acc.z << " " << data.gyro.x << " " << data.gyro.y << " " << data.gyro.z;
    return ss.str();
}

Mpu6050Data SerDesMpu6050Data::deserialize(const std::string& data)
{
    Mpu6050Data mpu6050Data;
    std::stringstream ss(data);
    ss >> mpu6050Data.acc.x >> mpu6050Data.acc.y >> mpu6050Data.acc.z >> mpu6050Data.gyro.x >> mpu6050Data.gyro.y >> mpu6050Data.gyro.z;
    return mpu6050Data;
}

} // ser_des
