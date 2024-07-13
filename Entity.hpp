#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Point.hpp"
#include "Size.hpp"
#include "Rect.hpp"
#include "Sprite.hpp"
#include <string>

class Entity_t {
    public:
        Entity_t() {}

        Entity_t(const Point_t& pos,
                     const Size_t& sz,
                     const std::string& sprite_path,
                     const Renderer_t& renderer)
                     : m_pos(pos), m_size(sz)
        {
            m_sprite = new Sprite_t(sz,sprite_path,renderer);
        }

        Entity_t(const Point_t& pos,
                     const Size_t& sz,
                     Sprite_t* sprite=nullptr)
                     : m_pos(pos), m_size(sz), m_sprite(sprite){}

        virtual ~Entity_t() {
            delete m_sprite;
        }

        void setPos(const Point_t& pos) {
            m_pos = pos;
        }

        void setSize(const Size_t& size) {
            m_size = size;
        }

        const Point_t& getPos() const {
            return m_pos;
        }

        const Size_t& getSize() const {
            return m_size;
        }

        Rect_t getRect() const{
            return Rect_t(m_pos,m_size);
        }

        Point_t& pos() {
            return m_pos;
        }

        Size_t& size() {
            return m_size;
        }

        Sprite_t*& sprite() {
            return m_sprite;
        }

        void destroy() {
            m_pos       = Point_t(0,0);
            m_size      = Size_t(0,0);
            m_enabled   = false;
            delete m_sprite;
        }

        void draw() {

        }

        void disable() { m_enabled = false; }
        void enable() { m_enabled = true; }
        bool isDisabled() const { return m_enabled; };
        bool isEnabled() const { return m_enabled; };

    protected:
        Sprite_t* m_sprite = nullptr;
        Point_t m_pos;
        Size_t m_size;
        bool m_enabled = true;
};

#endif // !ENTITY_HPP
