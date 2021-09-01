#pragma once

#include "CSystem.hpp"

class MovementSystem : CSystem {

  public:
    MovementSystem(entt::registry* manager) : CSystem(manager){}

    bool init();
    void update(float dt, float ups);
};
