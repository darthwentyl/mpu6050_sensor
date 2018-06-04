#include <iostream>
#include <unistd.h>
#include <implementation/Mpu6050.hpp>

using namespace implementation;
using namespace interface;

constexpr int32_t MPU_6050_ADDR = 0x68;

int main()
{
    std::unique_ptr<SensorIfc> sensor(new Mpu6050(MPU_6050_ADDR));
    while(1)
    {
        sensor->read();
        sensor->print();
        sleep(1);
    }
    return 0;
}
