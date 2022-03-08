#include "../../../include/ECS/Systems/ControllerSystem.hpp"

bool ControllerSystem::init(){
  return true;
}
void ControllerSystem::handleInput(sf::Event e){
  if (e.type == sf::Event::KeyPressed){

    /* if (e.key.code == sf::Keyboard::D){ */

    /* } */
    /* if (e.key.code  == sf::Keyboard::A){ */

    /* } */
    /* if (e.key.code  == sf::Keyboard::S){ */

    /* } */
    /* if (e.key.code  == sf::Keyboard::W){ */

    /* } */

  }
}
void ControllerSystem::update(float dt, float ups){
  auto view = m_entityManager->view<StateComponent, ControllerComponent,MovementComponent>();
  for (auto entity: view){

    auto &con = view.get<ControllerComponent>(entity);
    if (con.id == 1){
      auto &states = view.get<StateComponent>(entity);
      auto &mov = view.get<MovementComponent>(entity);

      mov.velx = 0;
      mov.vely = 0;
      states.status = StateComponent::STATUS::IDLE;

      if (sf::Keyboard::isKeyPressed(con.keys["Left"])) {
        mov.velx = -5;
        states.facing = StateComponent::DIRECTION::EAST;
        states.status = StateComponent::STATUS::WALKING;
      }
      if (sf::Keyboard::isKeyPressed(con.keys["Right"])) {
        mov.velx = 5;
        states.facing = StateComponent::DIRECTION::WEST;
        states.status = StateComponent::STATUS::WALKING;
      }
      if (sf::Keyboard::isKeyPressed(con.keys["Up"])) {
        mov.vely = -5;
        states.facing = StateComponent::DIRECTION::NORTH;
        states.status = StateComponent::STATUS::WALKING;
      }
      if (sf::Keyboard::isKeyPressed(con.keys["Down"])) {
        mov.vely = 5;
        states.facing = StateComponent::DIRECTION::SOUTH;
        states.status = StateComponent::STATUS::WALKING;
      }
      if (sf::Keyboard::isKeyPressed(con.keys["Jump"])) {
        mov.vely = 5;
        states.facing = StateComponent::DIRECTION::SOUTH;
        states.status = StateComponent::STATUS::JUMPING;
      }
    }
  }
}
