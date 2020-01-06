//
// Created by piptouque on 06/01/2020.
//

#ifndef WORLD_IMAKER_OMEGAFUNCTOR_HPP
#define WORLD_IMAKER_OMEGAFUNCTOR_HPP

#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>

#include <vector>
#include <algorithm>

#include "Types.hpp"
#include "Vec3D.hpp"
#include "Exception.hpp"

#include "RadialFunctor.hpp"

namespace wim
{
    /** TEMPLATE ALIASES **/
    template<typename T>
    using VecPoint = Eigen::Matrix<Point<T>, 1, Eigen::Dynamic, Eigen::RowMajor>;
    template<typename D>
    using VecScalar=  Eigen::Matrix<D, 1, Eigen::Dynamic>;
    template<class C>
    using VecValues = Eigen::Matrix<C, 1, Eigen::Dynamic> ;

    template<typename T, typename D>
    class OmegaSolver
    {
    private:
        typedef Eigen::Matrix<D, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> MatrixScalar;

    public:
        VecScalar<D> buildRadialVec(const Point<T>& position, const VecPoint<T>& points, const RadialFunctor<D>& phi, const DistanceFunctor<T,D>& distance) const
        {
            SizeInt n;
            n = points.size();
            VecScalar<D> vec(n);
            for(SizeInt i=0; i<n; ++i)
            {
                vec(i) = phi(distance(position, points(i)));
            }
            return vec;
        }
        VecScalar<D> solve(const VecPoint<T>& points, const VecScalar<D>& weights, const RadialFunctor<D>& phi, const DistanceFunctor<T, D>& distance) const

        {
            /** Building matrix of distances  **/
            MatrixScalar M = this->buildRadialMatrix(points, phi, distance);
            /** Solving M*omegas = weights **/
           // VecScalar<D> omegas(n);
            return M.qr().solve(weights);

        }
    private:
        MatrixScalar buildRadialMatrix(const VecPoint<T>& points, const RadialFunctor<D>& phi, const DistanceFunctor<T, D>& distance) const
        {
            SizeInt n = points.size();
            MatrixScalar M(n,n);
            for(SizeInt i=0; i<n; ++i)
            {
                M(i) = this->buildRadialVec(points.at(i), points, phi, distance);
            }
            return M;
        }
    };

    template<class C, typename T, typename D>
    class OmegaFunctor
    {
    public:
        typedef Eigen::Array<D, 1, Eigen::Dynamic> ArrayScalar;
        typedef Eigen::Array<C, 1, Eigen::Dynamic> ArrayValues;
    private:
        VecPoint<T> _points;
        //VecScalar<D> _weights;
        VecValues<C> _values;
        RadialFactory<D> _factory;
        RadialFunctor<D> _phi;
        DistanceFunctor<T, D> _distance;
        OmegaSolver<T,D> _solver;
        VecScalar<D> _omegas;
    public:
        OmegaFunctor() = default;

        OmegaFunctor(const VecPoint<T>& points, const VecScalar<D> weights, const VecValues<C>& values, const RadialMethod method, const D epsilon= static_cast<T>(1)) :
                _points(points), _values(values), _factory(), _phi(_factory.makeRadial(method, epsilon)),
                _distance(), _solver()
        {
            if( _points.size() != _values.size()
                || _points.size() != weights.size() )
            {
                throw Exception(ExceptCode::INIT_ERROR, 1, "Points and values must be of the same dimension.");
            }
            /* Solving linear system for the omega vector. */
            _omegas = _solver(_points, weights, _phi, _distance);
        }

        bool operator()(C& result, const Point<T>& position) const
        {
            /* If there is indeed a cube in this position..
             * return true, and set result.
             * else return false;
             * */
            if( !this->isInterpolatedOccupied(position) )
            {
                return false;
            }
            result = this->interpolate(position);
            return true;
        }


    private:
        C interpolate(const Point<T>& position) const
        {
            SizeInt n = _points.size();
            ArrayScalar vecPhi = _solver.buildRadialVec(position, _points, _phi, _distance).array();
            ArrayValues iValues = _values.array();
            C result(iValues(0)*vecPhi(0)*_omegas(0));
            for(SizeInt i=1; i<n; ++i)
            {
                //C class needs to overload intern operator+ and scalar operator*

                result += iValues(i)*vecPhi(i)*_omegas(i);
            }
            return result;
        }
        ///brief: checks whether the position will be occupied after interpolation.
        bool isInterpolatedOccupied(const Point<T>& position) const
        {
           //occupation condition: sum > 0.
           VecScalar<D> vecPhi = _solver.buildRadialVec(position, _points, _phi, _distance);
           D result = _omegas.dot(vecPhi);
           return result > 0;
        }

    };
    template<class C, typename T, typename D>
    using OmegaFunctorPtr = std::unique_ptr<OmegaFunctor<C,T,D>>;
}

#endif //WORLD_IMAKER_OMEGAFUNCTOR_HPP
