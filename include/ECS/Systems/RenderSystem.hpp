#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "CSystem.hpp"

class RenderSystem : CSystem {

  public:
    RenderSystem(entt::registry* manager) : CSystem(manager){}

    bool init();
    void update(float dt, float ups);
    void render(sf::RenderWindow& window);

};
