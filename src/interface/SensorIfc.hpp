#pragma once

#include <stdint.h>

namespace interface 
{

class SensorIfc
{
public:
    virtual ~SensorIfc() = default;

    virtual void read() = 0;
    virtual void printRaw() = 0;
    virtual void printHumanReadable() = 0;
    virtual void printKalman() = 0;
};

} // interface
