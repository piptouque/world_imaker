//
// Created by piptouque on 19/11/2019.
//

#include "../include/wim/CubeWorld.hpp"


namespace wim
{
    Cube& CubeWorld::operator()(const XUint x, const YUint y, const ZUint z)
    {
        try
        {
            return this->operator()(x,z).cube(y);
        }
        catch(Exception& e)
        {
            e.addMessageHead(std::string("In  CubeStack (")+std::to_string(x)+", "+std::to_string(y)+") :");
            throw;
        }
    }

    CubeWorld CubeWorld::Random(const XUint width, const ZUint length) {
        YUint height = (width + length) /2;
        CubeWorld world(width, length);
        for (XUint x = 0; x < width; ++x) {
            for (ZUint z = 0; z < length; ++z) {
                world(x, z) = CubeStack::Random(height, 0, height);
            }
        }
        return world;
    }

}