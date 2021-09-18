#include "../../../include/ECS/Systems/AnimationSystem.hpp"
#include <iostream>

bool AnimationSystem::init() { return true; }
bool AnimationSystem::isDurationOver(Animation &anim) {
  return anim.currentDuration >= anim.duration;
}
void AnimationSystem::updateAnimation(Animation &anim, float dt) {
  anim.currentDuration += dt;
  if (isDurationOver(anim)) {
    anim.currentDuration = 0;
    anim.currentFrame = (anim.currentFrame + 1) % anim.frames.size();
  }
}
void AnimationSystem::update(float dt, float ups) {
  typedef std::pair<StateComponent::STATUS, StateComponent::DIRECTION> States;

  auto view = m_entityManager->view<StateComponent, AnimationComponent>();
  for (auto entity : view) {
    auto &stateComponent = view.get<StateComponent>(entity);
    auto &animationComponent = view.get<AnimationComponent>(entity);
    auto spriteComponent = animationComponent.spriteComponent;

    States pair = {stateComponent.status, stateComponent.facing};

    // Like Animation System
    if (!(animationComponent.animations.find(pair) ==
          animationComponent.animations.end())) {
      updateAnimation(animationComponent.animations[pair], dt);
      if (animationComponent.animations[pair].texture) {
        // WARN: This could be to expensive... setting texture in everyframe???
        spriteComponent->sprite.setTexture(
            *animationComponent.animations[pair].texture);
        spriteComponent->sprite.setTextureRect(
            animationComponent.animations[pair]
                .frames[animationComponent.animations[pair].currentFrame]);
      }
    } else {
      // INFO: We enter here if we don't have any animation with the state
      spriteComponent->sprite.setTexture(*textureManager->getTexture("test"));
    }
  }
}
