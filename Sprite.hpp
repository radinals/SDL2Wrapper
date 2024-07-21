#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL_render.h>
#include <iostream>
#include <string>
#include "Rect.hpp"
#include "Texture.hpp"

class Sprite_t {
    public:
        explicit Sprite_t() {};

        explicit Sprite_t(Renderer_t& renderer,
                          const std::string& path,
                          int max_frame_count,
                          const Size_t& size = Size_t(0,0),
                          const Point_t& startpos = Point_t(0,0));

        explicit Sprite_t(Sprite_t& other);
        explicit Sprite_t(Sprite_t&& other) noexcept;

        virtual ~Sprite_t() {};

        Sprite_t& operator=(Sprite_t& other) {
            std::cout << "CPY = \n";
            m_texture = other.m_texture;
            m_frame = other.m_frame;
            m_rotate_angle = other.m_rotate_angle;
            m_flip = other.m_flip;
            m_max_frame_count = other.m_max_frame_count;
            return *this;
        }

        Sprite_t& operator=(Sprite_t&& other ){
            m_texture = std::move(other.m_texture);
            m_frame = std::move(other.m_frame);
            m_rotate_angle = other.m_rotate_angle;
            m_flip = other.m_flip;
            m_max_frame_count = other.m_max_frame_count;
            return *this;
        }

        void setFrameSize(int w, int h) {m_frame.w = w; m_frame.h = h; }
        void setFramePos(int x, int y) {m_frame.x = x; m_frame.y = y; }

        void setFrameSize(Size_t sz) { setFrameSize(sz.w,sz.h); }
        void setFramePos(Point_t pos) {setFramePos(pos.x,pos.y); }

        void setFrame(unsigned int n=0);
        void next(unsigned int n=1);
        void prev(unsigned int n=1);
        void flipHorizontal();
        void flipVertical();
        void rotate(int angle=0);
        Texture_t& texture() { return m_texture; }

        Rect_t getFrameRect() const { return m_frame; }
        Size_t getFrameSize() const { return m_frame.getSize(); }
        Point_t getFrameStartPos() const { return m_frame.getPoint(); }
        SDL_RendererFlip getFlip() const { return m_flip; }
        int getRotationAngle() const { return m_rotate_angle; }
        const Texture_t& getTexture() const { return m_texture; }

    protected:
        Texture_t m_texture;
        int m_rotate_angle = 0;
        int m_max_frame_count = 0;
        Rect_t m_frame;
        SDL_RendererFlip m_flip = SDL_RendererFlip::SDL_FLIP_NONE;
};

#endif // !SPRITE_HPp
