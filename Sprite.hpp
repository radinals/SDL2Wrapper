#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL_render.h>
#include <string>
#include "Rect.hpp"
#include "Texture.hpp"

// DESC: Representation of a single Spritesheet
// TODO: the naming of most methods is BAD
// TODO: set offset of a frame?
// TODO: frame count start from 0/1?

class Sprite_t {
    public:
        explicit Sprite_t() {}

        explicit Sprite_t(Renderer_t& renderer,
                          const std::string& path,
                          int max_frame_count,
                          const Size_t& size,
                          const Point_t& startpos);

        explicit Sprite_t(Renderer_t& renderer,
                          const std::string& path,
                          int max_frame_count,
                          int x, int y, int w, int h);

        explicit Sprite_t(Sprite_t& other);
        explicit Sprite_t(Sprite_t&& other) noexcept;

        virtual ~Sprite_t() { delete m_texture; }

        Sprite_t& operator=(const Sprite_t& other) noexcept {
            if (this != &other) {
                m_texture = other.m_texture;
                m_frame_rect = other.m_frame_rect;
                m_rotate_angle = other.m_rotate_angle;
                m_flip = other.m_flip;
                m_max_frame_count = other.m_max_frame_count;
            }
            return *this;
        }

        Sprite_t& operator=(Sprite_t&& other ) noexcept {
            if (this != &other) {
                m_texture = other.m_texture;
                other.m_texture = nullptr;
                m_frame_rect = other.getFrameRect();
                m_rotate_angle = other.getRotationAngle();
                m_flip = other.m_flip;
                m_max_frame_count = other.m_max_frame_count;
            }
            return *this;
        }

        void setFrameSize(int w, int h) {m_frame_rect.w = w; m_frame_rect.h = h; }
        void setFramePos(int x, int y) {m_frame_rect.x = x; m_frame_rect.y = y; }

        void setFrameSize(Size_t sz) { setFrameSize(sz.w,sz.h); }
        void setFramePos(Point_t pos) { setFramePos(pos.x,pos.y); }

        void setSpacing(int s) { m_spacing = s; } 
       
        int getCurrentFrame() const { return m_current_frame + 1; };

        void setFrame(int n=0);
        void next(int n=1);
        void prev(int n=1);
        void flipHorizontal();
        void flipVertical();
        void rotate(int angle=0);
        Texture_t& texture() { return *m_texture; }

        const Rect_t& getFrameRect() const { return m_frame_rect; }

        Point_t getFrameStartPos() const { return m_frame_rect.getPoint(); }
        SDL_RendererFlip getFlip() const { return m_flip; }
        int getRotationAngle() const { return m_rotate_angle; }
        const Texture_t& getTexture() const { return *m_texture; }

    protected:
        Texture_t* m_texture = nullptr;
        int m_rotate_angle = 0;
        int m_current_frame = 1;
        int m_max_frame_count = 0;
        int m_spacing = 0;
        Rect_t m_frame_rect; // a single sprite frame rectangle (box)
        SDL_RendererFlip m_flip = SDL_RendererFlip::SDL_FLIP_NONE;
};

#endif // !SPRITE_HPp
