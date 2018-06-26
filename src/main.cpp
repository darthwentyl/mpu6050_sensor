#include <implementation/Mpu6050.hpp>
#include <ser_des/SerDesMpu6050Data.hpp>
#include <ser_des/SerDesOrientation.hpp>
#include <kalman_filter/KalmanFilterMpu6050.hpp>
#include <utils/PrintMpu6050Data.hpp>

#include <iostream>
#include <chrono>
#include <thread>
#include <memory>

#include <unistd.h>

using namespace implementation;
using namespace interface;
using namespace kalman_filter;
using namespace data_structure;
using namespace ser_des;
using namespace utils;

constexpr int32_t MPU_6050_ADDR = 0x68;

int main()
{
    using namespace std::chrono_literals;
    std::unique_ptr<SensorIfc> sensor(new Mpu6050(MPU_6050_ADDR));
    
    Mpu6050Data mpu6050RawData;
    Mpu6050Data mpu6050NormalizeData;
    PrintMpu6050Data printer;
    std::unique_ptr<KalmanFilterIfc> kalman = std::make_unique<KalmanFilterMpu6050>(mpu6050NormalizeData.acc, mpu6050NormalizeData.gyro);
    while(1)
    {
        system("clear");
        sensor->read();

        mpu6050RawData = SerDesMpu6050Data::deserialize(sensor->getRawData());
        mpu6050NormalizeData = SerDesMpu6050Data::deserialize(sensor->getNormalizeData());
        
        printer.printRawData(mpu6050RawData);
        printer.printNormalizeData(mpu6050NormalizeData);
        
        kalman->update();
        printer.printOrientation(SerDesOrientation::deserialize(kalman->get()));
                
        std::this_thread::sleep_for(100ms);
    }
    return 0;
}
