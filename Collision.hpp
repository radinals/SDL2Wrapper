#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "Rect.hpp"
#include "RectF.hpp"
#include "Point.hpp"
#include "PointF.hpp"

namespace Collision {
    bool checkAABB(const Rect_t& A,  const Rect_t& B);
    bool checkAABB(const RectF_t& A, const RectF_t& B);
    bool checkAABB(const Point_t& aMin,  const Point_t& aMax,  const Point_t& bMin,  const Point_t& bMax);
    bool checkAABB(const PointF_t& aMin, const PointF_t& aMax, const PointF_t& bMin, const PointF_t& bMax);
};

#endif // !COLLISION_HPP
