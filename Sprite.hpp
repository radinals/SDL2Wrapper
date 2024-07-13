#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL_render.h>
#include <string>
#include "Point.hpp"
#include "Size.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

class Sprite_t {
    public:
        enum class SpriteFlip { NONE, HORIZONTAL, VERTICAL };

        Sprite_t(const Renderer_t& renderer, const std::string&filepath) {
            m_texture = Texture_t(renderer,filepath);
        }

        Sprite_t(const Size_t& size, const std::string& filepath, Renderer_t renderer) {
            m_texture = Texture_t(renderer,filepath);
        }

        int getCurrentFrame() { return m_frame; }
        int getCurrentRow() { return m_row; }

        void setCurrentFrame(int frame) {m_frame = frame;}
        void setCurrentRow(int row) {m_row = row;}

        void draw(int x, int y, int w, int h, SDL_RendererFlip flip=SDL_FLIP_NONE, int force_index=-1);
        void draw(const Point_t& pos, const Size_t& sz, SDL_RendererFlip flip=SDL_FLIP_NONE, int force_index=-1);

    protected:
        Texture_t m_texture;
        Size_t m_size;
        Point_t m_pos;
        int m_frame = -1;
        int m_row   = -1;
};

#endif // !SPRITE_HPP
