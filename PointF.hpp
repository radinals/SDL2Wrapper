#ifndef POINTF_HPP
#define POINTF_HPP

#include <SDL2/SDL_rect.h>
#include <cmath>

class PointF_t : public SDL_FPoint {
public:
    explicit PointF_t() : SDL_FPoint { 0, 0 } { }
    explicit PointF_t(float x, float y) : SDL_FPoint { x, y } { }

    PointF_t operator+(const PointF_t &other) const
    {
        return PointF_t(x + other.x, y + other.y);
    }

    PointF_t operator-(const PointF_t &other) const
    {
        return PointF_t(x - other.x, y - other.y);
    }

    PointF_t operator*(const PointF_t &other) const
    {
        return PointF_t(x * other.x, y * other.y);
    }

    PointF_t operator/(const PointF_t &other) const
    {
        return PointF_t(x / other.x, y / other.y);
    }

    PointF_t operator%(const PointF_t &other) const
    {
        return PointF_t(fmod(x , other.x), fmod(y , other.y));
    }

    PointF_t operator+(float scalar) const
    {
        return PointF_t(x + scalar, y + scalar);
    }

    PointF_t operator-(float scalar) const
    {
        return PointF_t(x - scalar, y - scalar);
    }

    PointF_t operator*(float scalar) const
    {
        return PointF_t(x * scalar, y * scalar);
    }

    PointF_t operator/(float scalar) const
    {
        return PointF_t(x / scalar, y / scalar);
    }

    PointF_t operator%(float scalar) const
    {
        return PointF_t(fmod(x, scalar), fmod(y, scalar));
    }

    PointF_t &operator+=(const PointF_t &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    PointF_t &operator+=(float scalar)
    {
        x += scalar;
        y += scalar;
        return *this;
    }

    PointF_t &operator-=(const PointF_t &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    PointF_t &operator-=(float scalar)
    {
        x -= scalar;
        y -= scalar;
        return *this;
    }

    PointF_t &operator*=(const PointF_t &other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    PointF_t &operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    PointF_t &operator/=(const PointF_t &other)
    {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    PointF_t &operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    PointF_t &operator=(const PointF_t &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    bool operator==(const PointF_t &other) const
    {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const PointF_t &other) const
    {
        return (x != other.x) || (y != other.y);
    }
};

#endif    // !POINTF_HPP
