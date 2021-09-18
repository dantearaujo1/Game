#include "../../../include/ECS/Systems/RenderSystem.hpp"

bool RenderSystem::init() {return true;}

void RenderSystem::update(float dt, float ups) {

  auto view = m_entityManager->view<SpriteComponent>();

  for (auto entity : view) {

    auto &spriteComponent = view.get<SpriteComponent>(entity);
    auto &sprite = spriteComponent.sprite;
    auto position = spriteComponent.position;

    if(!position){return;}
    sprite.setPosition(position->x,position->y);

  }

}
void RenderSystem::render(sf::RenderWindow& window){

  auto view = m_entityManager->view<SpriteComponent>();

  for (auto entity : view) {

    window.draw(view.get<SpriteComponent>(entity).sprite);

  }
}
