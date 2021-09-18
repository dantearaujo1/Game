#pragma once

#include "CSystem.hpp"
#include "../../Managers/SceneManager.hpp"
#include "../../Managers/AnimationManager.hpp"

class AnimationSystem : CSystem {

public:
  AnimationSystem(entt::registry *manager) : CSystem(manager) {}

  bool init();
  void update(float dt, float ups);
  void updateAnimation(Animation& anim, float dt);
  bool isDurationOver(Animation& anim);

  SceneManager* textureManager{nullptr};
  AnimationManager animationManager;

};
