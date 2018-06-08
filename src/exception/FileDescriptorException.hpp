#pragma once

#include <stdexcept>
#include <string>

namespace exception
{
    
class FileDescriptorException : public std::runtime_error
{
public:
    FileDescriptorException(const std::string& msg) :
        std::runtime_error(msg)
    {}
};
    
} // exception
