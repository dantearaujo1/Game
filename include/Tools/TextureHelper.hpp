#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"

class TextureHelper {
public:
  TextureHelper(sf::Vector2i tileSize, sf::Vector2i textureSize);
  TextureHelper(TextureHelper &&) = default;
  TextureHelper(const TextureHelper &) = default;
  TextureHelper &operator=(TextureHelper &&) = default;
  TextureHelper &operator=(const TextureHelper &) = default;
  ~TextureHelper();

  sf::IntRect getTile(int posx, int posy);
  int getTileID(int posx, int posy);
  sf::IntRect getTileByID(int id, bool rowFirst = true);
  sf::Vector2i getTextureSize() { return m_textureSize; }
  sf::Vector2i getTilesLength() { return m_tilesLength; }
  void setTileSize(int width, int height) {
    m_tileSize = sf::Vector2i(width, height);
  }
  void setTileSize(const sf::Vector2i &size) { m_tileSize = size; }
  sf::Vector2i getTileSize() const { return m_tileSize; }

private:
  sf::Vector2i m_tileSize;
  sf::Vector2i m_textureSize;
  sf::Vector2i m_tilesLength;
};
