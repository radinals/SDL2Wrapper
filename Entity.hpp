#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Point.hpp"
#include "Renderer.hpp"
#include "Size.hpp"
#include "Rect.hpp"
#include "Sprite.hpp"
#include <string>
#include <cassert>

class Entity_t {
    public:
        Entity_t() {}

        Entity_t(const Point_t& pos,
                 const Size_t& sz,
                 Sprite_t*& sprite)
                 : m_entity_area(pos,sz)
        {
            if (sprite != nullptr) {
                m_sprite = sprite;
                m_ext_sprite = true;
            } else {
                exit(1);
            }
        }

        Entity_t(const Point_t& pos,
                 const Size_t& sz,
                 const std::string& sprite_path,
                 Renderer_t& renderer,
                 int max_frame_count)
                 : m_entity_area(pos,sz)
        {
            m_sprite = new Sprite_t(renderer,sprite_path,max_frame_count,sz,pos); // create the spritesheet k
        }

        virtual ~Entity_t() {
            if (!m_ext_sprite) {
                delete m_sprite;
            }
        }

        Rect_t& Rect() {
            return m_entity_area;
        }

        const Rect_t& Rect() const {
            return m_entity_area;
        }

        Sprite_t*& Sprite() {
            return m_sprite;
        }

        const Sprite_t& Sprite() const {
            return *m_sprite;
        }

        void hide() {
            m_enabled   = false;
        }

        void draw(Renderer_t& renderer) {
            if (m_enabled) {  
                m_sprite->getFrameRect();
                renderer.drawSprite(*m_sprite, &m_entity_area);
            }
        }

        void disable() { m_enabled = false; }
        void enable() { m_enabled = true; }
        bool isDisabled() const { return m_enabled; };
        bool isEnabled() const { return m_enabled; };

    protected:
        bool m_ext_sprite = false;
        Sprite_t*  m_sprite = nullptr;
        Rect_t m_entity_area;
        bool m_enabled = true;
};

#endif // !ENTITY_HPP
