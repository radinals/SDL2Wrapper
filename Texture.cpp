#include "Texture.hpp"
#include <SDL2/SDL_render.h>

Texture_t::Texture_t(const Renderer_t& renderer, uint32_t format, SDL_TextureAccess access,
                     int w, int h, SDL_ScaleMode mode): m_renderer(renderer)
{
    m_renderer = renderer;
    createTexture(access,format,w,h,mode);
}

Texture_t::Texture_t(const Renderer_t& renderer, uint32_t format, SDL_TextureAccess access,
                     const Size_t& sz,SDL_ScaleMode mode): m_renderer(renderer) {
    m_renderer = renderer;
    createTexture(access,format,sz.w,sz.h,mode);
}

Texture_t::Texture_t(const Renderer_t& renderer, std::string path) {
    m_renderer = renderer;
    loadImage(path);
}

void Texture_t::loadImage(const std::string& path) {
    SDL_Surface *tmp = SDL_LoadBMP(path.c_str());
    m_texture = SDL_CreateTextureFromSurface(m_renderer.getRenderer(), tmp);
    SDL_FreeSurface(tmp);
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

void Texture_t::createTexture(SDL_TextureAccess access_type,
                              uint32_t pixel_format,
                              int w, int h,
                              SDL_ScaleMode mode)
{
    setScaleMode(mode);
    SDL_CreateTexture(m_renderer.getRenderer(), pixel_format, access_type, w,h);
}

void Texture_t::setBlendMode(SDL_BlendMode mode) {
    SDL_SetTextureBlendMode(m_texture, mode);
}

int Texture_t::getAlphaMod() {
    uint8_t a;
    SDL_GetTextureAlphaMod(m_texture, &a);
    return a;
}

SDL_BlendMode Texture_t::getBlendMode() {
    SDL_BlendMode b;
    SDL_GetTextureBlendMode(m_texture, &b);
    return b;
}

std::tuple<int,int,int> Texture_t::getColorMod() {
    uint8_t r, g, b;
    SDL_GetTextureColorMod(m_texture, &r, &g, &b);
    return std::tuple(r,g,b);
}

SDL_ScaleMode Texture_t::getScaleMode() {
    SDL_ScaleMode mode;
    SDL_GetTextureScaleMode(m_texture, &mode);
    return mode;
}
