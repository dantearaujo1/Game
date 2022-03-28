#include "../../../include/ECS/Systems/MovementSystem.hpp"
#include <iostream>

bool MovementSystem::init() {return true;}
void MovementSystem::update(float dt, float ups) {
  auto view = m_entityManager->view<PositionComponent, MovementComponent>();


  for (auto entity : view) {
    auto &pComp = view.get<PositionComponent>(entity);
    auto &mComp = view.get<MovementComponent>(entity);

    auto orig = sf::Vector2f(pComp.x,pComp.y);
    auto target = sf::Vector2f(pComp.x + mComp.velx * 32.0f, pComp.y + mComp.vely * 32.0f);

    auto lerp = orig + (target - orig) * mComp.elapsedTime/mComp.delay;
    mComp.elapsedTime += dt;

    if(mComp.elapsedTime < mComp.delay){
      pComp.x = lerp.x;
      pComp.y = lerp.y;
      continue;
    }
    lerp = target;
    mComp.isMoving = false;


  }
}

sf::Vector2f MovementSystem::lerp(sf::Vector2f start, sf::Vector2f end, float epsilon){
  return start + epsilon * (end - start);
}
