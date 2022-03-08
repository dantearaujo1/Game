#include "../include/Managers/TileManager.hpp"

TileManager::TileManager(ResourceManager<sf::Texture> *manager)
    : m_resources(manager),
      m_helper(sf::Vector2i(32.0f, 32.0f),
               sf::Vector2i(m_resources->getResource("map")->getSize())) {}

TileManager::~TileManager() {}

void TileManager::createTile(int texLoc, float x, float y, float width,
                             float height, const std::string &id,
                             TILETYPE type) {

  int index = m_tiles.size();
  Tile *tempTile =
      new Tile(sf::Vector2f(x, y), sf::Vector2f(width, height), type);
  m_tiles.push_back(tempTile);

  sf::Texture &texture = *m_resources->getResource(id);
  setTileTexture(index, texture);
  setTextureRect(index, m_helper.getTileByID(texLoc));
}
bool TileManager::setTileTexture(int index, const sf::Texture &texture) {
  // TODO: CHECK IF EVERYTHING IS OK TO RETURN TRUE
  m_tiles[index]->getSprite().setTexture(texture);
  return true;
}

void TileManager::update(float dt, float ups) {
  for (auto &tile : m_tiles) {
    tile->update(dt, ups);
  }
}
void TileManager::draw(sf::RenderWindow &window) {
  for (auto &tile : m_tiles) {
    tile->draw(window);
  }
}
void TileManager::setTextureRect(int index, sf::IntRect rect) {
  if (m_tiles[index]) {

    TILETYPE tp = m_tiles[index]->getType();

    m_tiles[index]->getSprite().setTextureRect(rect);
  }
}
