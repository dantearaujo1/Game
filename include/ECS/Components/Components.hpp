#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <string>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

struct PositionComponent {
  int x{0};
  int y{0};
  PositionComponent() = default;
  PositionComponent(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

struct MovementComponent {
  int velx{0};
  int vely{0};
  bool moving{false};
  MovementComponent() = default;
};

struct ControllerComponent {
  std::map<const std::string, sf::Keyboard::Key> keys;
  std::map<const std::string, sf::Mouse::Button> mouse;
};

struct SpriteComponent {
  sf::Sprite sprite;
  PositionComponent* position;
  SpriteComponent() = default;
};

struct StateComponent {
  enum STATUS {
    IDLE,
    WALKING,
    RUNNING,
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

struct Animation {
  Animation(){};
  std::vector<sf::IntRect> frames;
  float duration{2.0f};
  float currentDuration{0};
  int currentFrame{0};
  bool repeat{true};
  bool reverse{true};
};

struct AnimationComponent {
  std::map<std::pair<StateComponent::STATUS, StateComponent::DIRECTION>,
           Animation>
      animations;

  SpriteComponent* spriteComponent{nullptr};
  AnimationComponent() = default;
};
