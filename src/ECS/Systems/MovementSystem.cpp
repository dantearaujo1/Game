#include "../../../include/ECS/Systems/MovementSystem.hpp"

bool MovementSystem::init() {return true;}
void MovementSystem::update(float dt, float ups) {
  auto view = m_entityManager->view<PositionComponent, MovementComponent>();
  for (auto entity : view) {
    auto &pComp = view.get<PositionComponent>(entity);
    auto &mComp = view.get<MovementComponent>(entity);
    pComp.x += mComp.velx * dt;
    pComp.y += mComp.vely * dt;
  }
}
