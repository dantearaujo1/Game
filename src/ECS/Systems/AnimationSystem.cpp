#include "../../../include/ECS/Systems/AnimationSystem.hpp"

bool AnimationSystem::init() { return true; }
void AnimationSystem::update(float dt, float ups) {
  auto view =
      m_entityManager
          ->view<PositionComponent, StateComponent,AnimationComponent, SpriteComponent>();
  for (auto entity : view) {
    auto &pos = view.get<PositionComponent>(entity);
    auto &states = view.get<StateComponent>(entity);
    auto &ps = view.get<SpriteComponent>(entity).sprite;
    auto &ani = view.get<AnimationComponent>(entity);

    // Like Animation System
    ani.currentFrameDuration += dt;
    if (ani.currentFrameDuration >= ani.frameDuration) {
      ani.currentFrameDuration = 0;
      if (ani.currentFrame < ani.frames[ani.currentFrameString].size() - 1) {
        ani.currentFrame += 1;
      } else {
        ani.currentFrame = 0;
      }
    }
    ps.setTextureRect(ani.frames[ani.currentFrameString][ani.currentFrame]);
    ps.setPosition(pos.x, pos.y);
  }
}
