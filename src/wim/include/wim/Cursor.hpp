//
// Created by piptouque on 29/12/2019.
//

#ifndef WORLD_IMAKER_CURSOR_HPP
#define WORLD_IMAKER_CURSOR_HPP

#pragma once


#include "Types.hpp"
#include "Vec3D.hpp"

#include "CubeWorld.hpp"

#include "Selectable.hpp"
#include "Selection.hpp"

#include "ProceduralGenerator.hpp"

namespace wim
{

    //rate at which the weight of a selected cube will be raised/lowered
    static constexpr FloatType DEFAULT_WEIGHTMOD_RATE = 1.f;


    class Cursor : public Displayable
    {
    private:
        Point3Uint _position;
        WorldPtr _world;
        SelectionPtr _selection;
        ProceduralGeneratorPtr _generator;
        RadialMethod _method;
    public:
        Cursor(const WorldPtr& world);
        ~Cursor() = default;

        void moveX(const XInt delta);
        void moveY(const YInt delta);
        void moveZ(const ZInt delta);

        void setPosition(const XUint x, const YUint y, const ZUint z);
        void setPosition(const Point3Uint& position);
        const Point3Uint& getPosition() const;

        inline XUint getWorldWidth() const {return _world->getWidth();}
        inline YUint getWorldHeight() const {return _world->getHeight();}
        inline ZUint getWorldLength() const {return _world->getLength();}

        inline const SelectionPtr& selection() const {return _selection;}

        bool getHoveredCubePtr(CubePtr& cubePtr) const;
        void selectHoveredCube() const;
        void deselectHoveredCube() const;

        void moveSelectedCube() const;

        void clearSelected() const;
        void clearDeleted() const;


        void addHoveredCube(const Cube& cube) const;
        void eraseHoveredCube() const;

        void extrudeHoveredCube() const;
        void digHoveredCube() const;

        void changeTextureHoveredCube() const;
        void changeWeightHoveredSelected(const bool raise) const;

        void generateFromSelection();

        void setRadialMethod(const RadialMethod method);
        void setNextRadialMethod();


        bool isOccupied(const Point3Uint& position) const;
        bool isHoveredHigherStackEmpty() const;
        bool isHoveredLowerStackEmpty() const;

        DisplayPattern getDisplayPattern() const override;

    private:
        void setX(const XUint x);
        void setY(const YUint y);
        void setZ(const ZUint z);

        bool isPositionValid(const XUint x, const ZUint z) const;
        bool isPositionValid(const Point3Uint& position) const;



    };

    typedef std::unique_ptr<Cursor> CursorPtr;
}
 #endif //WORLD_IMAKER_CURSOR_HPP
