#ifndef WORLD_IMAKER_CUBE_HPP
#define WORLD_IMAKER_CUBE_HPP

#pragma once

#include <iostream>
#include <utility>

#include "Displayable.hpp"
#include "Material.hpp"

namespace wim
{
    ///Class for the structural Cube
    /*Will not be Displayed directly
    * But rather through the CubeStack class
     */
    class Cube : public Displayable //Needs to inherit Displayable as public in order to cast it as such when rendering.
    {
    private:
        //No need for radius since every cube in the grid is the same size
        //inherits Material from Displayable.
    public:
        Cube() = default;
        Cube(const Material& material);
        Cube(const Cube& cube) = default;
        ~Cube() = default;

        Cube& operator=(Cube cube);

        static Cube Random();

        DisplayPattern getDisplayPattern() const override {return DisplayPattern::FULL_CUBE;}

        friend std::ostream& operator<<(std::ostream& out, const Cube& cube);

    };
    inline std::ostream& operator<<(std::ostream& out, const Cube& cube)
    {
        return out << cube._material;
    }

}

#endif //WORLD_IMAKER_CUBE_HPP
