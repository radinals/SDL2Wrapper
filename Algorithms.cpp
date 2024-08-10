#include "Algorithms.hpp"

#include <list>
#include "Rect.hpp"

Rect_t
Algorithms::alignCenter(const Rect_t &a, const Rect_t &b) {
    return Rect_t(b.getCenter().x - getHalf(a.w) , b.getCenter().y - getHalf(a.h),a.w,a.h);
    return Rect_t(0,0,0,0);
}

// std::list<Point_t>
// Algorithms::bresenhamLine(const Point_t& start, const Point_t& dest) {
//
// }
