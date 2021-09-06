#pragma once

#include "CSystem.hpp"

class AnimationSystem : CSystem {

  public:
    AnimationSystem(entt::registry* manager) : CSystem(manager){}

    bool init();
    void update(float dt, float ups);
};
