#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include "Entity.hpp"
#include "Renderer.hpp"
#include <map>
#include <string>

class EntityManager_t {
    public:
        EntityManager_t(){}
        EntityManager_t(Renderer_t renderer): m_renderer(renderer) {}

        void setRenderer(Renderer_t& renderer) { m_renderer = renderer; }

        void removeEntity(const std::string& id);
        void addEntity(Entity_t*, const std::string& id);

        Entity_t* getEntity(const std::string& id);
        const Entity_t& getEntity(const std::string& id) const;

        void draw();

    private:
        std::map<std::string, Entity_t*> m_entities;
        Renderer_t m_renderer;
};

#endif // !ENTITYMANAGER_HPP
