#pragma once

#include "CSystem.hpp"
#include "SFML/Window/Event.hpp"

class ControllerSystem : CSystem {

  public:
    ControllerSystem(entt::registry* manager) : CSystem(manager){}

    // TODO create a proper init function
    bool init();
    void handleInput(sf::Event e);
    void update(float dt, float ups);
};
