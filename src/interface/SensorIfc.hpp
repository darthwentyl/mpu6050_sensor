#pragma once

namespace interface 
{

class SensorIfc
{
public:
    virtual ~SensorIfc() = default;

    virtual void read() = 0;
    virtual void print() = 0;
};

} // interface
