#pragma once

#include <data_structure/GyroscopeData.hpp>

namespace interface
{
    
class GyroscopeIfc
{
public:
    virtual ~GyroscopeIfc() = default;
    
    virtual data_structure::GyroscopeData getRawData() = 0;
    virtual data_structure::GyroscopeData getConvertedData() = 0;
    virtual void printRawData() = 0;
    virtual void printHumanReadableData() = 0;
    virtual void readData() = 0;
};
    
} // interface
