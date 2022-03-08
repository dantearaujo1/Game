#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#include <string>

enum class TILETYPE{
  NONE,
  WALL,
  FLOOR,
  WATER,
  SAND,
  GRASS,
  ICE,
};

class Tile{
public:
  Tile(sf::Vector2f position = sf::Vector2f(0.0f,0.0f), sf::Vector2f size = sf::Vector2f(16.0f,16.0f), TILETYPE type = TILETYPE::NONE);
  ~Tile();

  TILETYPE getType() const { return m_type; }
  sf::Sprite& getSprite() { return m_sprite; }

  void update(float dt, float ups);
  void draw(sf::RenderWindow& window);

// This should be Private?
private:
  TILETYPE m_type;
  sf::Vector2f m_position;
  sf::Vector2f m_size;
  sf::Sprite m_sprite;
};
