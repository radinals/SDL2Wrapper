#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL_rect.h>

#include "Point.hpp"
#include "Size.hpp"

class Rect_t : public SDL_Rect {
public:
    explicit Rect_t(int x, int y, int w, int h) : SDL_Rect { x, y, w, h } { }
    explicit Rect_t(const Point_t& pos=Point_t(0,0),const Size_t& sz=Size_t(0,0)) :
        SDL_Rect { pos.x, pos.y, sz.w, sz.h } { }

    Rect_t& operator=(const Rect_t& other) {
        x = other.x;
        y = other.y;
        w = other.w;
        h = other.h;
        return *this;
    }

    bool operator==(const Rect_t& other)
    {
        return x == other.x && y == other.y && w == other.w && h == other.h;
    }

    Size_t getSize() const { return Size_t(w,h); }
    Point_t getPoint() const { return Point_t(x,y); }

    void setSize(const Size_t& sz) {setSize(sz.w, sz.h);};
    void setPoint(const Point_t& p) {setPoint(p.x,p.y);};

    void setSize(int _w, int _h) { w = _w; h = _h; }
    void setPoint(int _x, int _y) { x = _x; y = _y; }

    constexpr int getArea() const { return w * h; }

    Point_t getCenter() const;
    Point_t getTopLeft() const;
    Point_t getTopRight() const;
    Point_t getBottomLeft() const;
    Point_t getBottomRight() const;
};

#endif // !RECT_HPP
