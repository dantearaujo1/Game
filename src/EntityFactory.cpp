#include "../include/EntityFactory.hpp"

EntityFactory::EntityFactory(entt::registry* ecs, SceneManager* director, AnimationFactory* afct) : m_ecs(ecs) , m_director(director), m_animationFactory(afct)
{
}

EntityFactory::~EntityFactory()
{
}
entt::entity EntityFactory::createPlayer(int id){
  const auto entity = m_ecs->create();

  auto &cposition = m_ecs->emplace<PositionComponent>(entity, 400, 300);
  auto &cstates = m_ecs->emplace<StateComponent>(entity);
  auto &cmovement = m_ecs->emplace<MovementComponent>(entity);
  auto &scomponent = m_ecs->emplace<SpriteComponent>(entity);
  auto &canimation = m_ecs->emplace<AnimationComponent>(entity);
  auto &ccontroller = m_ecs->emplace<ControllerComponent>(entity);

  cmovement.velx = 0;
  cmovement.vely = 0;

  // scomponent.position = &cposition;
  scomponent.sprite.setTexture(*m_director->getTexture("child"));
  scomponent.sprite.setTextureRect(sf::IntRect(2 * 32, 1 * 64, 32, 64));
  scomponent.sprite.setPosition(cposition.x, cposition.y);

  ccontroller.keys["Left"] = sf::Keyboard::A;
  ccontroller.keys["Right"] = sf::Keyboard::D;
  ccontroller.keys["Down"] = sf::Keyboard::S;
  ccontroller.keys["Up"] = sf::Keyboard::W;
  ccontroller.keys["Jump"] = sf::Keyboard::Space;
  ccontroller.id = id;

  canimation.spriteComponent = &scomponent;

  canimation.animations[StateComponent::STATUS::WALKING][StateComponent::DIRECTION::SOUTH] = m_animationFactory->getAnimation("child_walking_south");
  canimation.animations[StateComponent::STATUS::WALKING][StateComponent::DIRECTION::NORTH] = m_animationFactory->getAnimation("child_walking_north");
  canimation.animations[StateComponent::STATUS::WALKING][StateComponent::DIRECTION::EAST] = m_animationFactory->getAnimation("child_walking_right");
  canimation.animations[StateComponent::STATUS::WALKING][StateComponent::DIRECTION::WEST] = m_animationFactory->getAnimation("child_walking_left");

  canimation.currentAnimation = std::make_pair(cstates.facing,m_animationFactory->getAnimation("child_walking_left"));

  return entity;

}
