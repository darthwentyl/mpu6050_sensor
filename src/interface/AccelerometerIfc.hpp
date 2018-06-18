#pragma once

#include <data_structure/AccelerometerData.hpp>

namespace interface
{

class AccelerometerIfc
{
public:
    virtual ~AccelerometerIfc() = default;
    
    virtual data_structure::AccelerometerData getRawData() = 0;
    virtual data_structure::AccelerometerData getConvertedData() = 0;
    virtual void printRawData() = 0;
    virtual void printHumanReadableData() = 0;
    virtual void readData() = 0;
};

} // interface
