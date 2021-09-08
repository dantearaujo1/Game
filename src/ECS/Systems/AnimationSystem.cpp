#include "../../../include/ECS/Systems/AnimationSystem.hpp"
#include <iostream>

bool AnimationSystem::init() { return true; }
void AnimationSystem::update(float dt, float ups) {
  auto view =
      m_entityManager
          ->view<StateComponent, AnimationComponent>();
  for (auto entity : view) {
    auto &states = view.get<StateComponent>(entity);
    auto &ani = view.get<AnimationComponent>(entity);
    auto spriteComponent = ani.spriteComponent;

    std::pair<StateComponent::STATUS, StateComponent::DIRECTION> pair = {
        states.status, states.facing};

    // Like Animation System
    ani.animations[pair].currentDuration += dt;
    if (ani.animations[pair].currentDuration >= ani.animations[pair].duration) {
      ani.animations[pair].currentDuration = 0;
      if (ani.animations[pair].currentFrame <
          ani.animations[pair].frames.size() - 1) {
        ani.animations[pair].currentFrame += 1;
      } else {
        ani.animations[pair].currentFrame = 0;
      }
    }
    if (!(ani.animations.find(pair) == ani.animations.end())) {
      spriteComponent->sprite.setTextureRect(
          ani.animations[pair].frames[ani.animations[pair].currentFrame]);
    } else {
      std::cout << "ENTERED HERE" << std::endl;
      spriteComponent->sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
    }

  }
}
Animation *AnimationSystem::createAnimation(int frames) { return nullptr; }
