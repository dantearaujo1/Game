#include "../../../include/ECS/Systems/RenderSystem.hpp"

bool RenderSystem::init() {return true;}
void RenderSystem::update(float dt, float ups) {
  auto view = m_entityManager->view<PositionComponent, SpriteComponent>();
  for (auto entity : view) {
    auto &pComp = view.get<PositionComponent>(entity);
    auto &sprite = view.get<SpriteComponent>(entity).sprite;
    sprite.setPosition(pComp.x,pComp.y);
  }
}
void RenderSystem::render(sf::RenderWindow& window){
  auto view = m_entityManager->view<SpriteComponent>();
  for (auto entity : view) {
    window.draw(view.get<SpriteComponent>(entity).sprite);
  }

}
