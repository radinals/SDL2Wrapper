#include "Sprite.hpp"
#include <SDL2/SDL_render.h>

Sprite_t::Sprite_t(Renderer_t& renderer,
                  const std::string& path,
                  int max_frame_count,
                  const Size_t& size,
                  const Point_t& startpos)
{
    m_max_frame_count = max_frame_count;
    m_frame_rect = Rect_t(startpos,size);
    m_texture = new Texture_t(renderer,path);
}

Sprite_t::Sprite_t(Renderer_t& renderer,
                  const std::string& path,
                  int max_frame_count,
                  int x, int y, int w, int h)
{
    m_max_frame_count = max_frame_count;
    m_frame_rect = Rect_t(x,y,w,h);
    m_texture = new Texture_t(renderer,path);
}

Sprite_t::Sprite_t(Sprite_t& other) {
    m_texture = other.m_texture;
    m_frame_rect = other.m_frame_rect;
    m_rotate_angle = other.m_rotate_angle;
    m_max_frame_count = other.m_max_frame_count;
    m_flip = other.m_flip;
}

Sprite_t::Sprite_t(Sprite_t&& other) noexcept {
    m_texture = other.m_texture;
    m_frame_rect = other.m_frame_rect;
    m_rotate_angle = other.m_rotate_angle;
    m_flip = other.m_flip;
    m_max_frame_count = other.m_max_frame_count;
}

void Sprite_t::setFrame(int n) {
    m_frame_rect.x = (m_frame_rect.w * n) + m_spacing;
    m_current_frame = n + 1;
    if (m_frame_rect.x >= (m_frame_rect.w * m_max_frame_count)) { m_frame_rect.x = 0; m_current_frame = 0; }
};

void Sprite_t::next(int n) {
    m_frame_rect.x += (m_frame_rect.w * n) + m_spacing;
    m_current_frame += n;
    if (m_frame_rect.x >= (m_frame_rect.w * m_max_frame_count)) { m_frame_rect.x = 0; m_current_frame = 0; }
}

void Sprite_t::prev(int n) {
    m_frame_rect.x -= (m_frame_rect.w * n) + m_spacing;
    if (m_frame_rect.x < 0) { m_frame_rect.x = 0; }
}

void Sprite_t::flipHorizontal() {
    if (m_flip != SDL_RendererFlip::SDL_FLIP_HORIZONTAL) { m_flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL; };
}

void Sprite_t::flipVertical() {
    if (m_flip != SDL_RendererFlip::SDL_FLIP_VERTICAL) { m_flip = SDL_RendererFlip::SDL_FLIP_VERTICAL; };
}

void Sprite_t::rotate(int angle) {
    if (angle != m_rotate_angle) {m_rotate_angle = angle;}
}
