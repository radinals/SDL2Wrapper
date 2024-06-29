#include "Rect.hpp"
#include "Point.hpp"
#include "Algorithms.hpp"
#include <SDL2/SDL_rect.h>

Point_t
Rect_t::getCenter() const
{
    return Point_t(x + Algorithms::getHalf(w), y + Algorithms::getHalf(h));
}

Point_t
Rect_t::getTopLeft() const
{
    return Point_t(x, y);
}

Point_t
Rect_t::getTopRight() const
{
    return Point_t(x + w, y);
}

Point_t
Rect_t::getBottomLeft() const
{
    return Point_t(x, y + h);
}

Point_t
Rect_t::getBottomRight() const
{
    return Point_t(x + w, y + h);
}
