#include <utils/PrintMpu6050Data.hpp>

#include <iostream>

namespace utils
{

void PrintMpu6050Data::printRawData(const data_structure::Mpu6050Data& data)
{
    std::cout << "RAW_____________________________________" << std::endl;
    std::cout << "acc.x = " << data.acc.x << std::endl;
    std::cout << "acc.y = " << data.acc.y << std::endl;
    std::cout << "acc.z = " << data.acc.z << std::endl;
    std::cout << "gyro.x = " << data.gyro.x << std::endl;
    std::cout << "gyro.y = " << data.gyro.y << std::endl;
    std::cout << "gyro.z = " << data.gyro.z << std::endl;
    std::cout << "________________________________________" << std::endl;
}

void PrintMpu6050Data::printNormalizeData(const data_structure::Mpu6050Data& data)
{
    std::cout << "NORMALIZE_______________________________" << std::endl;
    std::cout << "acc.x = " << data.acc.x << "[g]" << std::endl;
    std::cout << "acc.y = " << data.acc.y << "[g]" << std::endl;
    std::cout << "acc.z = " << data.acc.z << "[g]" << std::endl;
    std::cout << "gyro.x = " << data.gyro.x << "[dec/s]" << std::endl;
    std::cout << "gyro.y = " << data.gyro.y << "[dec/s]" << std::endl;
    std::cout << "gyro.z = " << data.gyro.z << "[dec/s]" << std::endl;
    std::cout << "________________________________________" << std::endl;
}

void PrintMpu6050Data::printOrientation(const data_structure::OrientationData& data)
{
    std::cout << "ORIENTATION_____________________________" << std::endl;
    std::cout << "pitch = " << data.pitch << std::endl;
    std::cout << "roll = " << data.roll << std::endl;
    std::cout << "________________________________________" << std::endl;
}

} // utils
