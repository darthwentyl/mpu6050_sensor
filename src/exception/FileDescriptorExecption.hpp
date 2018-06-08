#pragma once

#include <stdexcept>
#include <string>

namespace exception
{
    
class FileDescriptorExecption : public std::runtime_error
{
public:
    FileDescriptorExecption(const std::string& msg) :
        std::runtime_error(std::string(msg))
    {}
};
    
} // exception
