#include "../../../include/ECS/Systems/AnimationSystem.hpp"
#include <iostream>

bool AnimationSystem::init() { return true; }
void AnimationSystem::update(float dt, float ups) {
  auto view = m_entityManager->view<PositionComponent, StateComponent,
                                    AnimationComponent, SpriteComponent>();
  for (auto entity : view) {
    auto &pos = view.get<PositionComponent>(entity);
    auto &states = view.get<StateComponent>(entity);
    auto &ps = view.get<SpriteComponent>(entity).sprite;
    auto &ani = view.get<AnimationComponent>(entity);

    std::pair<StateComponent::STATUS,StateComponent::DIRECTION> pair = {states.status,states.facing};
    // Like Animation System
    ani.animations[pair].currentDuration += dt;
    if (ani.animations[pair].currentDuration >=
        ani.animations[pair].duration) {
      ani.animations[pair].currentDuration = 0;
      if (ani.animations[pair].currentFrame <
          ani.animations[pair].frames.size() - 1) {
        ani.animations[pair].currentFrame += 1;
      } else {
        ani.animations[pair].currentFrame = 0;
      }
    }
    if (!(ani.animations.find(pair) == ani.animations.end()))
    {
      ps.setTextureRect(ani.animations[pair].frames[ani.animations[pair].currentFrame]);
    }
    else{
      std::cout << "ENTERED HERE" << std::endl;
      ps.setTextureRect(sf::IntRect(0,0,32,64));
    }
    ps.setPosition(pos.x, pos.y);
  }
}
Animation *AnimationSystem::createAnimation(int frames) {
  return nullptr;
}
