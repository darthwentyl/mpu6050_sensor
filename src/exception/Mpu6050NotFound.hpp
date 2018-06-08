#pragma once

#include <stdexcept>
#include <string>

namespace execption
{
    
class Mpu6050NotFound : public std::runtime_error
{
public:
    Mpu6050NotFound(const std::string& msg) :
        std::runtime_error(std::string(msg))
    {}
};
    
} // execption
