#include "../../../include/ECS/Systems/RenderSystem.hpp"
#include <iostream>

bool RenderSystem::init() {
  // m_tileManager.init(nullptr);
  return true;
}

void RenderSystem::update(float dt, float ups) {

  auto view = m_entityManager->view<SpriteComponent, PositionComponent>();

  for (auto entity : view) {

    auto &spriteComponent = view.get<SpriteComponent>(entity);
    auto &sprite = spriteComponent.sprite;
    auto &position = view.get<PositionComponent>(entity);

    // if(!position){return;}
    sprite.setPosition(position.x,position.y);

  }

  // m_tileManager.update(dt,ups);

}
void RenderSystem::render(sf::RenderWindow& window){

  auto view = m_entityManager->view<SpriteComponent, PositionComponent>();

  for (auto entity : view) {

    window.draw(view.get<SpriteComponent>(entity).sprite);
  }
  // m_tileManager.render(window);
}
