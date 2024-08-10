#include "Texture.hpp"
#include "Renderer.hpp"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <cassert>

Texture_t::Texture_t(Renderer_t&renderer, uint32_t format, SDL_TextureAccess access,
                     int w, int h, SDL_ScaleMode mode)
{
    createTexture(renderer, format, w, h, mode);
}

Texture_t::Texture_t(Renderer_t& renderer, uint32_t format, SDL_TextureAccess access,
                     const Size_t& sz,SDL_ScaleMode mode){
    createTexture(renderer, format, sz.w, sz.h, mode);
}

Texture_t::Texture_t(Renderer_t& renderer, std::string path) {
    loadBitmap(renderer, path);
}

Texture_t::Texture_t(Texture_t && other) noexcept {
    m_texture = other.m_texture;
    other.m_texture = nullptr;
}

Texture_t::Texture_t(const Texture_t & other) {
    m_texture = other.m_texture;
}

Texture_t& Texture_t::operator=(const Texture_t& other) {
    if (this != &other) {
        // destroying the old exsisting texture
        SDL_DestroyTexture(m_texture);
        m_texture = other.m_texture;
    }
    return *this;
}

Texture_t& Texture_t::operator=(Texture_t&& other) noexcept {
    if (this != &other) {
        SDL_DestroyTexture(m_texture);
        m_texture = other.m_texture;
        other.m_texture = nullptr;
    }
    return *this;
}

void Texture_t::loadBitmap(Renderer_t& renderer, const std::string& path) {
    assert(renderer.getRenderer() != nullptr);

    SDL_Surface *tmp = SDL_LoadBMP(path.c_str());

    assert(tmp != nullptr);

    m_texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), tmp);
    SDL_FreeSurface(tmp);

    assert(m_texture != nullptr);

    assert(renderer.getRenderer() != nullptr);
}

void Texture_t::setScaleMode(SDL_ScaleMode mode) {
    SDL_SetTextureScaleMode(m_texture, mode);
}

void Texture_t::setColorMod(int r, int g, int b) {
    SDL_SetTextureColorMod(m_texture, r, g, b);
}

void Texture_t::setAlphaMod(uint8_t a) {
    SDL_SetTextureAlphaMod(m_texture, a);
}

void Texture_t::setColorRGBAMod(const Color_t& rgba) {
    setAlphaMod(rgba.getA());
    setColorMod(rgba.getR(), rgba.getG(), rgba.getB());
}

void Texture_t::createTexture(Renderer_t& renderer,
                              uint32_t format,
                              int access, int w, int h,
                              SDL_ScaleMode scale_method)
{
    assert(renderer.getRenderer() != nullptr);
    setScaleMode(scale_method);
    SDL_CreateTexture(renderer.getRenderer(), format, access, w,h);
}

void Texture_t::setBlendMode(SDL_BlendMode mode) {
    SDL_SetTextureBlendMode(m_texture, mode);
}

int Texture_t::getAlphaMod() {
    uint8_t a = 0;
    SDL_GetTextureAlphaMod(m_texture, &a);
    return a;
}

SDL_BlendMode Texture_t::getBlendMode() const {
    SDL_BlendMode b;
    SDL_GetTextureBlendMode(m_texture, &b);
    return b;
}

std::tuple<int,int,int> Texture_t::getColorMod() const {
    uint8_t r = 0, g = 0, b = 0;
    SDL_GetTextureColorMod(m_texture, &r, &g, &b);
    return std::tuple<int,int,int>(r,g,b);
}

SDL_ScaleMode Texture_t::getScaleMode() const {
    SDL_ScaleMode mode;
    SDL_GetTextureScaleMode(m_texture, &mode);
    return mode;
}
