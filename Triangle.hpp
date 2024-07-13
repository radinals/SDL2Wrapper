#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Point.hpp"
#include "Rect.hpp"
#include "Algorithms.hpp"
#include <cstring>

class Triangle_t {
    public:

        Triangle_t() {}

        Triangle_t(const Point_t& l, const Point_t& c, const Point_t& r) {
            m_points[0] = c;
            m_points[1] = l;
            m_points[2] = r;
        }
        Triangle_t(const Rect_t& r){
            m_points[0] = Point_t(r.getCenter().x,(r.getTopLeft().y -Algorithms::getHalf(r.h)));
            m_points[1] = r.getBottomLeft();
            m_points[2] = r.getBottomRight();
        }

        const Point_t& getTop() const { return m_points[0]; }
        const Point_t& getBottomLeft() const { return m_points[1]; }
        const Point_t& getBottomRight() const { return m_points[2]; }

    private:

    Point_t m_points[3];

};

#endif // !TRIANGLE_HPP
