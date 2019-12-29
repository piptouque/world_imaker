//
// Created by piptouque on 21/12/2019.
//

#ifndef WORLD_IMAKER_TYPES_HPP
#define WORLD_IMAKER_TYPES_HPP

#pragma once

#include <cstddef>

#define GLM_FORCE_RADIANS
#include <glimac/glm.hpp>


namespace wim
{
    typedef float FloatType;

    typedef std::size_t XUint, YUint, ZUint;
    typedef long int Xint, Yint, Zint;
    typedef std::size_t SizeInt;


    typedef glm::mat4 UniformMatrix;
}

#endif //WORLD_IMAKER_TYPES_HPP
