#include "../../include/Tools/TextureHelper.hpp"
#include <iostream>

TextureHelper::TextureHelper(sf::Vector2i tileSize, sf::Vector2i textureSize)
    : m_tileSize(tileSize), m_textureSize(textureSize),
      m_tilesLength(m_textureSize.x / m_tileSize.x,
                    m_textureSize.y / m_tileSize.y) {}

TextureHelper::~TextureHelper() {}
sf::IntRect TextureHelper::getTile(int posx, int posy) {
  if (posx < m_tilesLength.x && posy < m_tilesLength.y) {
    return sf::IntRect(posx * m_tileSize.x, posy * m_tileSize.y, m_tileSize.x,
                       m_tileSize.y);
  }
  return sf::IntRect(0, 0, 32, 32);
}
sf::IntRect TextureHelper::getTileByID(int id, bool rowFirst) {
  if ( id < m_tilesLength.x * m_tilesLength.y){
    if (rowFirst) {
      int x = id % m_tilesLength.x;
      int y = (id - x) / m_tilesLength.x;
      return sf::IntRect(x * m_tileSize.x, y * m_tileSize.y, m_tileSize.x,
                         m_tileSize.y);
    }
    return sf::IntRect(0, 0, 32, 32);
  }
  return sf::IntRect(0, 0, 32, 32);
}
