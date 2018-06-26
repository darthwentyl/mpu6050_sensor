#pragma once

#include <string>

namespace interface 
{

class SensorIfc
{
public:
    virtual ~SensorIfc() = default;

    virtual void read() = 0;
    virtual std::string getRawData() = 0;
    virtual std::string getNormalizeData() = 0;
};

} // interface
