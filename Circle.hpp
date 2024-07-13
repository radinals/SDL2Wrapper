#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"

class Circle_t {
public:
    explicit Circle_t();
    explicit Circle_t(int,int, int);

    Point_t getTopLeft();

    int getRadius();
    int getDiameter();
    int getCircumference();

    Point_t getCenter();

private:
    int m_radius=0;
};

#endif // !CIRCLE_HPP
