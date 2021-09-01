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
  MovementComponent() = default;
};

struct ControllerComponent {
  std::map<const std::string, sf::Keyboard::Key> keys;
  std::map<const std::string, sf::Mouse::Button> mouse;
};

struct SpriteComponent {
  sf::Sprite sprite;
  SpriteComponent() = default;
};

struct AnimationComponent {
  std::map<const std::string, std::vector<sf::IntRect>> frames;
  float frameDuration;
  std::string currentFrameString;
  float currentFrameDuration;
  int currentFrame{0};
  AnimationComponent() = default;
};

/* struct StateComponent { */
  /* std::map<const std::string, > states; */
/* }; */
