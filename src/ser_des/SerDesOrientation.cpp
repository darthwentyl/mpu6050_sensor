#include <ser_des/SerDesOrientation.hpp>

#include <sstream>

namespace ser_des
{

using namespace data_structure;

std::string SerDesOrientation::serialize(const data_structure::OrientationData& orientation)
{
    std::stringstream ss;
    ss << orientation.roll << " " << orientation.pitch;
    return ss.str();
}

OrientationData SerDesOrientation::deserialize(const std::string& data)
{
    OrientationData orientation;
    std::stringstream ss(data);
    ss >> orientation.roll >> orientation.pitch;
    return orientation;
}

} // ser_des
