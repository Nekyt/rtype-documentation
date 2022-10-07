/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

/**
 * It adds a component to an entity
 * 
 * @param e The entity to add the component to.
 * @param c The component type
 */
void ECS::ComponentManager::addComponent(ECS::Entity e, ECS::ComponentType c)
{
    std::map<ComponentType, IComp> compo;

    if (_eentities.find(e) == _eentities.end()) {
        compo.insert(std::pair<ComponentType, IComp>(c, createComponent(c)));
        _eentities.insert(std::pair<Entity, std::map<ComponentType, IComp>>(e, compo));
        _centities[c].push_back(e);
    } else {
        _eentities[e].insert(std::pair<ComponentType, IComp>(c, createComponent(c)));
        _centities[c].push_back(e);
    }
}

/**
 * It returns a reference to the component of type c of entity e
 * 
 * @return A reference to the component of type c of entity e.
 */
ECS::IComp &ECS::ComponentManager::getComponent(ECS::Entity e, ECS::ComponentType c)
{
    return _eentities[e][c];
}

/**
 * It returns a reference to the map of components for the given entity
 * 
 * @return A map of component types and components.
 */
std::map<ECS::ComponentType, ECS::IComp> &ECS::ComponentManager::getComponentList(Entity entity)
{
    return _eentities.at(entity);
}

/**
 * It returns a reference to the vector of entities that have the specified
 * component type
 * 
 * @return A vector of entities.
 */
std::vector<ECS::Entity> &ECS::ComponentManager::getEntityList(ComponentType type)
{
    return _centities.at(type);
}

/**
 * It creates a component of the type passed in parameter
 * 
 * @param c The type of component to create.
 * 
 * @return A component of the type specified in the parameter.
 */
ECS::IComp ECS::ComponentManager::createComponent(ECS::ComponentType c)
{
    if (c == ECS::ComponentType::ACCELERATION)
        return ECS::Acceleration();
    else if (c == ECS::ComponentType::BONUS)
        return ECS::Bonus();
    else if (c == ECS::ComponentType::CONTROLABLE)
        return ECS::Controlable(true);
    else if (c == ECS::ComponentType::PATTERN)
        return ECS::Pattern();
    else if (c == ECS::ComponentType::SPEED)
        return ECS::Speed(0);
    else if (c == ECS::ComponentType::POSITION)
        return ECS::Position(0, 0);
    else if (c == ECS::ComponentType::DAMAGE)
        return ECS::Damage(0);
    else if (c == ECS::ComponentType::ROTATION)
        return ECS::Rotate(0);
    else if (c == ECS::ComponentType::SOUND)
        return ECS::Sound();
    else if (c == ECS::ComponentType::HEALTH)
        return ECS::Health(0);
    else if (c == ECS::ComponentType::HITBOX)
        return ECS::Hitbox(0, 0);
    else if (c == ECS::ComponentType::SIZE)
        return ECS::Size(0, 0);
    else if (c == ECS::ComponentType::IDE)
        return ECS::ID(0);
    else if (c == ECS::ComponentType::TEXT)
        return ECS::Text(std::string(""));
    else if (c == ECS::ComponentType::TEXTURE)
        return ECS::Texture();
    else if (c == ECS::ComponentType::WEAPON)
        return ECS::Weapon();
}