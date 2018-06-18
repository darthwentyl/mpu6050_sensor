#pragma once

namespace interface
{

class KalmanFilterIfc
{
public:
    virtual ~KalmanFilterIfc() = default;
    
    virtual void update() = 0;
};

} // interface
