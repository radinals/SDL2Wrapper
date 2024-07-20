#include "Sprite.hpp"
#include <SDL2/SDL_render.h>

Sprite_t::Sprite_t(Renderer_t& renderer,
                  const std::string& path,
                  int max_frame_count,
                  const Size_t& size,
                  const Point_t& startpos)
{
    m_max_frame_count = max_frame_count;
    m_frame = Rect_t(startpos,size);
    m_texture = Texture_t(renderer,path);
    std::cout << "R" << m_frame.w << ' ' << m_frame.h << '\n';
}

Sprite_t::Sprite_t(Sprite_t& other) {
    m_texture = other.m_texture;
    m_frame = other.m_frame;
    m_rotate_angle = other.m_rotate_angle;
    m_max_frame_count = other.m_max_frame_count;
    m_flip = other.m_flip;
}

Sprite_t::Sprite_t(Sprite_t&& other) {
    m_texture = std::move(other.m_texture);
    m_frame = std::move(other.m_frame);
    m_rotate_angle = other.m_rotate_angle;
    m_flip = other.m_flip;
    m_max_frame_count = other.m_max_frame_count;
}

void Sprite_t::setFrame(unsigned int n) {
    m_frame.x = n * m_frame.w;
    if (m_frame.x >= (m_frame.w * m_max_frame_count)) { m_frame.x = 0; }
};

void Sprite_t::next(unsigned int n) {
    m_frame.x += (m_frame.w * n);
    if (m_frame.x >= (m_frame.w * m_max_frame_count)) { m_frame.x = 0; }
}

void Sprite_t::prev(unsigned int n) {
    m_frame.x -= (m_frame.w * n);
    if (m_frame.x < 0) { m_frame.x = 0; }
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
