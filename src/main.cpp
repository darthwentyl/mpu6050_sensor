#include <iostream>
#include <chrono>
#include <thread>

#include <unistd.h>

#include <implementation/Mpu6050.hpp>

using namespace implementation;
using namespace interface;

constexpr int32_t MPU_6050_ADDR = 0x68;

int main()
{
    using namespace std::chrono_literals;
    std::unique_ptr<SensorIfc> sensor(new Mpu6050(MPU_6050_ADDR));
    while(1)
    {
        system("clear");
        sensor->read();
        sensor->printRaw();
        sensor->printHumanReadable();
        sensor->printKalman();
        std::this_thread::sleep_for(100ms);
    }
    return 0;
}
