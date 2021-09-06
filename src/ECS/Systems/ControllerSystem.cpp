#include "../../../include/ECS/Systems/ControllerSystem.hpp"

bool ControllerSystem::init(){
  return true;
}
void handleInput(sf::Event e){
  if (e.type == sf::Event::KeyPressed){
    if (e.key.code == sf::Keyboard::D){

    }
    if (e.key.code  == sf::Keyboard::A){

    }
    if (e.key.code  == sf::Keyboard::S){

    }
    if (e.key.code  == sf::Keyboard::W){

    }
  }
}
void ControllerSystem::update(float dt, float ups){
  auto view = m_entityManager->view<StateComponent,AnimationComponent, ControllerComponent,MovementComponent>();
  for (auto entity: view){

    auto &con = view.get<ControllerComponent>(entity);
    auto &states = view.get<StateComponent>(entity);
    auto &mov = view.get<MovementComponent>(entity);
    auto &ani = view.get<AnimationComponent>(entity);

    mov.velx = 0;
    mov.vely = 0;

    if (sf::Keyboard::isKeyPressed(con.keys["Left"])) {
      mov.velx = -5;
      states.facing = StateComponent::DIRECTION::EAST;
      states.status = StateComponent::STATUS::WALKING;
      ani.currentFrameString = "Left";
    }
    if (sf::Keyboard::isKeyPressed(con.keys["Right"])) {
      mov.velx = 5;
      states.facing = StateComponent::DIRECTION::WEST;
      states.status = StateComponent::STATUS::WALKING;
      ani.currentFrameString = "Right";
    }
    if (sf::Keyboard::isKeyPressed(con.keys["Up"])) {
      mov.vely = -5;
      states.facing = StateComponent::DIRECTION::NORTH;
      states.status = StateComponent::STATUS::WALKING;
      ani.currentFrameString = "Up";
    }
    if (sf::Keyboard::isKeyPressed(con.keys["Down"])) {
      mov.vely = 5;
      states.facing = StateComponent::DIRECTION::SOUTH;
      states.status = StateComponent::STATUS::WALKING;
      ani.currentFrameString = "Down";
    }
  }

}
