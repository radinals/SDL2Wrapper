#include "Collision.hpp"

namespace Collision {
    bool checkAABB(const Point_t& aMin, const Point_t& aMax, const Point_t& bMin, const Point_t& bMax) {
        return (aMax.x >= bMin.x && aMin.x <= bMax.x && aMax.y <= bMin.y && aMin.y >= bMax.y);
    }

    bool checkAABB(const PointF_t& aMin, const PointF_t& aMax, const PointF_t& bMin, const PointF_t& bMax) {
        return (aMax.x >= bMin.x && aMin.x <= bMax.x && aMax.y <= bMin.y && aMin.y >= bMax.y);
    }

    bool checkAABB(const Rect_t& A, const Rect_t& B) {
        return checkAABB(A.getBottomLeft(), A.getTopRight(),B.getBottomLeft(),B.getTopRight());
    }

    bool checkAABB(const RectF_t& A, const RectF_t& B) {
        return checkAABB(A.getBottomLeft(), A.getTopRight(),B.getBottomLeft(),B.getTopRight());
    }

};
