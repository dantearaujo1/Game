#pragma once

#include "CSystem.hpp"

class MovementSystem : CSystem {

  public:
    MovementSystem(entt::registry* manager) : CSystem(manager){}

    bool init();
    void update(float dt, float ups);
    void move(sf::Vector2i direction);

    sf::Vector2f lerp(sf::Vector2f start, sf::Vector2f end, float epsilon);
};
