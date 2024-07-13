#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <cstdint>
#include <string>
#include "Renderer.hpp"
#include "Size.hpp"
#include <tuple>

class Texture_t {
    public:
        Texture_t();

        Texture_t(const Renderer_t& renderer, uint32_t format, SDL_TextureAccess access,
                  int w, int h, SDL_ScaleMode mode=SDL_ScaleModeLinear);

        Texture_t(const Renderer_t& renderer, uint32_t format, SDL_TextureAccess access,
                  const Size_t& sz, SDL_ScaleMode mode=SDL_ScaleModeLinear);

        Texture_t(const Renderer_t& renderer, std::string path);

        ~Texture_t() { SDL_DestroyTexture(m_texture); }

        void loadImage(const std::string& path);

        void createTexture(SDL_TextureAccess, uint32_t, int, int,
                           SDL_ScaleMode mode = SDL_ScaleModeLinear);

        void setColorMod(int r, int g, int b);
        void setAlphaMod(uint8_t a);
        void setBlendMode(SDL_BlendMode);
        void setScaleMode(SDL_ScaleMode);

        int getAlphaMod();
        SDL_BlendMode getBlendMode();
        std::tuple<int,int,int> getColorMod();
        SDL_ScaleMode getScaleMode();

        SDL_Texture* getTexture() { return m_texture; }

        void render(const Size_t* src_sz=nullptr,  const Size_t* dst_sz=nullptr, double angle=0, const Point_t* center=nullptr);

    protected:
        SDL_Texture* m_texture = nullptr;
        Renderer_t m_renderer;
};

#endif // !TEXTURE_HPP
