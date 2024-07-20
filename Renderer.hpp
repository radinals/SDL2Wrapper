#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <cstdint>

#include "Color.hpp"
#include "Point.hpp"
#include "PointF.hpp"
#include "Rect.hpp"
#include "RectF.hpp"
#include "Size.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Renderer_t {
public:
    Renderer_t() { }
    Renderer_t(SDL_Window*, int, uint32_t);
    Renderer_t(SDL_Renderer*);
    ~Renderer_t();

    SDL_Renderer* getRenderer() { return m_renderer; }

    void clear();
    void present();
    SDL_RendererInfo getInfo() const;

    void setColor(int, int, int, int);
    void setColor(const Color_t&);
    void setColor(const char color[]);

    void drawLine(const Point_t&, const Point_t&);
    void drawLine(const PointF_t&, const PointF_t&);
    void drawLine(int src_x, int src_y, int dest_x, int dest_y);

    void drawLines(const Point_t[], int count);
    void drawLines(const PointF_t[], int count);
    // void drawLines(std::vector<Point_t>&);

    void drawPoint(const Point_t&);
    void drawPoint(const PointF_t&);
    void drawPoint(int,int);

    void drawPoints(const Point_t[], int count);
    void drawPoints(const PointF_t[], int count);

    void drawRect(const Rect_t&);
    void drawRect(const RectF_t&);
    void drawRect(const Point_t&, const Size_t&);
    void drawRect(int sx,int sy, int w, int h);

    void drawRects(const Rect_t[], int count);
    void drawRects(const RectF_t[], int count);

    void drawFillRect(const Rect_t&);
    void drawFillRect(const Point_t&, const Size_t&);
    void drawFillRect(const RectF_t&);

    void drawFillRects(const Rect_t[], int count);
    void drawFillRects(const RectF_t[], int count);

    void drawCircle(const Circle_t&);
    void drawTriangle(const Triangle_t&);
    void renderCopy(const Texture_t&,
                    const Rect_t* src_rect=nullptr,
                    const Rect_t* dst_rect=nullptr);

    void renderCopyEx(const Texture_t&,
                    const Rect_t* src_rect=nullptr,
                    const Rect_t* dst_rect=nullptr,
                    double angle=0,
                    const Point_t* center=nullptr,
                    SDL_RendererFlip flip=SDL_RendererFlip::SDL_FLIP_NONE);

    void drawSprite(const Sprite_t&, const Rect_t* render_dst=nullptr);

    // void renderGeometry();

private:
    SDL_Renderer* m_renderer = nullptr;
};

#endif    // !RENDERER_HPP
