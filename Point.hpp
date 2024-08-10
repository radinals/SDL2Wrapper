#ifndef POINT_HPP
#define POINT_HPP

#include <SDL2/SDL_rect.h>

class Point_t : public SDL_Point {
public:
    explicit Point_t() : SDL_Point { 0, 0 } { }
    explicit Point_t(int _x, int _y) : SDL_Point { _x, _y } { }

    Point_t operator+(const Point_t &other) const
    {
        return Point_t(x + other.x, y + other.y);
    }

    Point_t operator-(const Point_t &other) const
    {
        return Point_t(x - other.x, y - other.y);
    }

    Point_t operator*(const Point_t &other) const
    {
        return Point_t(x * other.x, y * other.y);
    }

    Point_t operator/(const Point_t &other) const
    {
        return Point_t(x / other.x, y / other.y);
    }

    Point_t operator%(const Point_t &other) const
    {
        return Point_t(x % other.x, y % other.y);
    }

    Point_t operator+(int scalar) const
    {
        return Point_t(x + scalar, y + scalar);
    }

    Point_t operator-(int scalar) const
    {
        return Point_t(x - scalar, y - scalar);
    }

    Point_t operator*(int scalar) const
    {
        return Point_t(x * scalar, y * scalar);
    }

    Point_t operator/(int scalar) const
    {
        return Point_t(x / scalar, y / scalar);
    }

    Point_t operator%(int scalar) const
    {
        return Point_t(x % scalar, y % scalar);
    }

    Point_t &operator+=(const Point_t &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point_t &operator+=(int scalar)
    {
        x += scalar;
        y += scalar;
        return *this;
    }

    Point_t &operator-=(const Point_t &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point_t &operator-=(int scalar)
    {
        x -= scalar;
        y -= scalar;
        return *this;
    }

    Point_t &operator*=(const Point_t &other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Point_t &operator*=(int scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Point_t &operator/=(const Point_t &other)
    {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Point_t &operator/=(int scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Point_t &operator=(const Point_t &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    bool operator==(const Point_t &other) const
    {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point_t &other) const
    {
        return (x != other.x) || (y != other.y);
    }
};

#endif    // !POINT_HPP
