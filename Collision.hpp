#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "Rect.hpp"
#include "RectF.hpp"
#include "Point.hpp"
#include "PointF.hpp"

namespace Collision {
    bool checkAABB(const Rect_t& A, Rect_t& B);
    bool checkAABB(const RectF_t& A, RectF_t& B);
    bool checkAABB(const Point_t& aMin, Point_t& aMax, Point_t& bMin, Point_t& bMax);
    bool checkAABB(const PointF_t& aMin, PointF_t& aMax, PointF_t& bMin, PointF_t& bMax);
};

#endif // !COLLISION_HPP
