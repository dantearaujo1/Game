#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include <SFML/Graphics/Rect.hpp>
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

#include "../../Animation.hpp"

struct PositionComponent {
  int x{0};
  int y{0};
  PositionComponent(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

struct MovementComponent {
  int velx{0};
  int vely{0};
  MovementComponent() = default;
};

struct ControllerComponent {
  std::map<const std::string, sf::Keyboard::Key> keys;
  std::map<const std::string, sf::Mouse::Button> mouse;
  int id;
};

struct SpriteComponent {
  sf::Sprite sprite;
  sf::Texture* spriteTexture{nullptr};
  sf::IntRect currentFrame;
  // PositionComponent* position;
  SpriteComponent() = default;
};

struct StateComponent {
  enum STATUS {
    IDLE,
    WALKING,
    RUNNING,
    JUMPING,
  };
  enum DIRECTION {
    NORTH,
    SOUTH,
    EAST,
    WEST,
  };
  STATUS status{WALKING};
  DIRECTION facing{DIRECTION::SOUTH};
};

struct AnimationComponent {

  std::map<StateComponent::STATUS, std::map<StateComponent::DIRECTION,Animation*>> animations;
  std::pair<StateComponent::DIRECTION,Animation*> currentAnimation;
  StateComponent::DIRECTION facing{StateComponent::DIRECTION::EAST};
  SpriteComponent* spriteComponent{nullptr};

  AnimationComponent() = default;
};
