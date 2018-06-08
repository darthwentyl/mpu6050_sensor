#pragma once

#include <stdexcept>
#include <string>

namespace exception
{
    
class Mpu6050NotFoundException : public std::runtime_error
{
public:
    Mpu6050NotFoundException(const std::string& msg) :
        std::runtime_error(msg)
    {}
};
    
} // exception
