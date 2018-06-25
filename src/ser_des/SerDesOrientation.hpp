#pragma once

#include <data_structure/OrientationData.hpp>

#include <string>
#include <cfloat>
#include <cmath>

namespace ser_des 
{

class SerDesOrientation
{
public:
    static std::string serialize(const data_structure::OrientationData& orientation);
    static data_structure::OrientationData deserialize(const std::string& data);
};

} // ser_des
