#pragma once

#include <string>

namespace interface
{

class KalmanFilterIfc
{
public:
    virtual ~KalmanFilterIfc() = default;
    
    virtual void update() = 0;
    virtual std::string get() = 0;
};

} // interface
