#include "../../../include/ECS/Systems/AnimationSystem.hpp"
#include <iostream>

bool AnimationSystem::init() { return true; }
bool AnimationSystem::isDurationOver(Animation &anim) {
  return anim.currentDuration >= anim.framesData[anim.currentFrame]->duration;
}
void AnimationSystem::updateAnimation(Animation &anim, float dt) {
  anim.currentDuration += dt;
  if (isDurationOver(anim)) {
    anim.currentDuration = 0;
    anim.currentFrame = (anim.currentFrame + 1) % anim.framesData.size();
  }
}
void AnimationSystem::update(float dt, float ups) {

 auto view = m_entityManager->view<StateComponent, AnimationComponent>();

  for (auto entity : view) {
    auto &stateComponent = view.get<StateComponent>(entity);
    auto &animationComponent = view.get<AnimationComponent>(entity);
    auto spriteComponent = animationComponent.spriteComponent;
    Animation* animation = animationComponent.animations[stateComponent.status][stateComponent.facing];

    if(!spriteComponent){
      return;
    }
    if (!animation){
      return;
    }
    updateAnimation(*animation, dt);

    spriteComponent->sprite.setTextureRect(animation->framesData[animation->currentFrame]->frame);
  }
}
