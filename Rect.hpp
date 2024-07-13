#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL_rect.h>

#include "Point.hpp"
#include "Size.hpp"

class Rect_t : public SDL_Rect {
public:
    Rect_t() : SDL_Rect { 0, 0, 0, 0 } { }
    Rect_t(int x, int y, int w, int h) : SDL_Rect { x, y, w, h } { }
    Rect_t(const Point_t& pos, const Size_t& sz) : SDL_Rect { pos.x, pos.y, sz.w, sz.h } { }

    bool operator==(const Rect_t& other)
    {
        return x == other.x && y == other.y && w == other.w && h == other.h;
    }

    Point_t getCenter() const;
    Point_t getTopLeft() const;
    Point_t getTopRight() const;
    Point_t getBottomLeft() const;
    Point_t getBottomRight() const;
};

#endif    // !RECT_HPP
