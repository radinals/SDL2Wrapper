#include "Renderer.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "PointF.hpp"
#include "Rect.hpp"
#include "RectF.hpp"
#include "Size.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <cassert>
#include <iostream>
#include <SDL2/SDL_render.h>

Renderer_t::Renderer_t(SDL_Window* window, int index, uint32_t flags)
{
    m_renderer = SDL_CreateRenderer(window, index, flags);
}

Renderer_t::Renderer_t(SDL_Renderer* renderer) { m_renderer = renderer; }

Renderer_t::~Renderer_t() { std::cout << "RENDERER DESTROYED\n"; SDL_DestroyRenderer(m_renderer); }

SDL_RendererInfo
Renderer_t::getInfo() const {
   SDL_RendererInfo info;
   SDL_GetRendererInfo(m_renderer, &info);
   return info;
}

void
Renderer_t::clear()
{
    int e = SDL_RenderClear(m_renderer);
    if (e != 0) {
        std::cout << "CLEAR ERROR: " << SDL_GetError() << '\n';
        exit(0);
    }
}
void
Renderer_t::present()
{
    SDL_RenderPresent(m_renderer);
}

void
Renderer_t::setColor(int r, int g, int b, int a)
{
    int e = SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
    if (e != 0) {
        std::cout << "SET COLOR ERROR: " << SDL_GetError() << '\n';
        exit(0);
    }
}

void
Renderer_t::setColor(const Color_t& color)
{
    SDL_SetRenderDrawColor(m_renderer,
                           color.getR(),
                           color.getG(),
                           color.getB(),
                           color.getA());
}

void Renderer_t::setColor(const char color[]) {
    Color_t clr(color);
    SDL_SetRenderDrawColor(m_renderer,
                           clr.getR(),
                           clr.getG(),
                           clr.getB(),
                           clr.getA());
}

void
Renderer_t::drawLine(const Point_t& source, const Point_t& dest)
{
    SDL_RenderDrawLine(m_renderer, source.x, source.y, dest.x, dest.y);
}

void
Renderer_t::drawLine(const PointF_t& source, const PointF_t& dest)
{
    SDL_RenderDrawLineF(m_renderer, source.x, source.y, dest.x, dest.y);
}

void Renderer_t::drawLine(int src_x, int src_y, int dest_x, int dest_y) {
    SDL_RenderDrawLine(m_renderer, src_x, src_y, dest_x, dest_y);
}

void
Renderer_t::drawLines(const Point_t lines[], int count)
{
    SDL_RenderDrawLines(m_renderer, lines, count);
}

void
Renderer_t::drawLines(const PointF_t lines[], int count)
{
    SDL_RenderDrawLinesF(m_renderer, lines, count);
}

void
Renderer_t::drawPoint(const Point_t& point)
{
    SDL_RenderDrawPoint(m_renderer, point.x, point.y);
}

void
Renderer_t::drawPoint(const PointF_t& point)
{
    SDL_RenderDrawPointF(m_renderer, point.x, point.y);
}

void Renderer_t::drawPoint(int x,int y) {

    SDL_RenderDrawPoint(m_renderer, x, y);
}

void
Renderer_t::drawPoints(const Point_t points[], int count)
{
    SDL_RenderDrawPoints(m_renderer, points, count);
}

void
Renderer_t::drawPoints(const PointF_t points[], int count)
{
    SDL_RenderDrawPointsF(m_renderer, points, count);
}

void
Renderer_t::drawRect(const Rect_t& rect)
{
    SDL_RenderDrawRect(m_renderer, &rect);
}

void
Renderer_t::drawRect(const RectF_t& rect)
{
    SDL_RenderDrawRectF(m_renderer, &rect);
}

void
Renderer_t::drawRect(const Point_t& pos, const Size_t& size)
{
    Rect_t r(pos.x, pos.y, size.w, size.h);
    SDL_RenderDrawRect(m_renderer, &r);
}

void
Renderer_t::drawRects(const Rect_t rects[], int count)
{
    SDL_RenderDrawRects(m_renderer, rects, count);
}

void Renderer_t::drawRect(int sx,int sy, int w, int h) {
    drawRect(Rect_t(sx,sy,w,h));
}

void
Renderer_t::drawRects(const RectF_t rects[], int count)
{
    SDL_RenderDrawRectsF(m_renderer, rects, count);
}

void
Renderer_t::drawFillRect(const Rect_t& rect)
{
    SDL_RenderFillRect(m_renderer, &rect);
}

void
Renderer_t::drawFillRect(const RectF_t& rect)
{
    SDL_RenderFillRectF(m_renderer, &rect);
}

void
Renderer_t::drawFillRect(const Point_t& pos, const Size_t& size)
{
    Rect_t r(pos.x, pos.y, size.w, size.h);
    SDL_RenderFillRect(m_renderer, &r);
}

void
Renderer_t::drawFillRects(const Rect_t rects[], int count)
{
    SDL_RenderFillRects(m_renderer, rects, count);
}

void
Renderer_t::drawFillRects(const RectF_t rects[], int count)
{
    SDL_RenderFillRectsF(m_renderer, rects, count);
}

void Renderer_t::drawCircle(const Circle_t& circle) {

}

void Renderer_t::drawTriangle(const Triangle_t& triangle) {
    drawLine(triangle.getBottomLeft(),triangle.getTop());
    drawLine(triangle.getBottomRight(),triangle.getTop());
    drawLine(triangle.getBottomLeft(),triangle.getBottomRight());
}

void Renderer_t::renderCopy(const Texture_t& texture,
                            const Rect_t* src_rect,
                            const Rect_t* dst_rect)
{
    SDL_RenderCopy(m_renderer, texture.getTexture(), src_rect, dst_rect);
};

void Renderer_t::renderCopyEx(const Texture_t& texture,
                const Rect_t* src_rect,
                const Rect_t* dst_rect,
                double angle,
                const Point_t* center,
                SDL_RendererFlip flip)
{
    int e = SDL_RenderCopyEx(m_renderer,
                     texture.getTexture(),
                     src_rect, dst_rect,
                     angle, center,
                     flip);
    if (e != 0) {
        std::cout << "RENDERCOPYEX ERROR: " << SDL_GetError() << '\n';
        exit(0);
    }
}

void Renderer_t::drawSprite(const Sprite_t& sprite, const Rect_t* render_dst) {
    Rect_t frame_rect = sprite.getFrameRect();
    Point_t frame_rect_center = sprite.getFrameRect().getCenter();
    renderCopyEx(sprite.getTexture(), &frame_rect, render_dst,
                 sprite.getRotationAngle(),
                 nullptr, sprite.getFlip());
    std::cout << "R: " << frame_rect.w << 'X' << frame_rect.h << '\n';
}
