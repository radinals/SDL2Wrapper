#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <cstdint>
#include <string>
#include "Rect.hpp"
#include "Color.hpp"
#include "Size.hpp"
#include <tuple>
#include <iostream>

class Renderer_t;

class Texture_t {
    public:
        explicit Texture_t() {};

        explicit Texture_t(Renderer_t& renderer, uint32_t format, SDL_TextureAccess access,
                  int w, int h, SDL_ScaleMode mode=SDL_ScaleModeLinear);

        explicit Texture_t(Renderer_t& renderer, uint32_t format, SDL_TextureAccess access,
                  const Size_t& sz, SDL_ScaleMode mode=SDL_ScaleModeLinear);

        explicit Texture_t(Renderer_t& renderer, std::string path);

        Texture_t(Texture_t &&) noexcept;
        Texture_t(Texture_t &);

        Texture_t& operator=(Texture_t&);
        Texture_t& operator=(Texture_t&&);

        ~Texture_t() { std::cout <<(m_texture == nullptr ? "Empty " : "") << "TEXTURE DESTROYED" << '\n'; SDL_DestroyTexture(m_texture); }

        void loadBitmap(Renderer_t&, const std::string& path);
        // void loadImage(Renderer_t&, const std::string& path);

        void createTexture(Renderer_t& renderer,
                           uint32_t format, int access, int w, int h,
                           SDL_ScaleMode scale_method = SDL_ScaleModeLinear);

        void setColorMod(int r, int g, int b);
        void setAlphaMod(uint8_t a);
        void setColorRGBAMod(const Color_t& rgba);
        void setBlendMode(SDL_BlendMode);
        void setScaleMode(SDL_ScaleMode);

        int getAlphaMod();
        SDL_BlendMode getBlendMode() const;
        std::tuple<int,int,int> getColorMod() const;
        SDL_ScaleMode getScaleMode() const;

        SDL_Texture*const getTexture() const { return m_texture; }

    protected:
        SDL_Texture* m_texture = nullptr;
};

#endif // !TEXTURE_HPP
