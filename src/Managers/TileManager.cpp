#include "../include/Managers/TileManager.hpp"

TileManager::TileManager(ResourceManager<sf::Texture>* manager)
    : m_resources(manager) {}

TileManager::~TileManager() {}
void TileManager::createTile(float x, float y, float width, float height, const std::string& id, TILETYPE type) {
  int index = m_tiles.size();
  Tile *tempTile = new Tile(sf::Vector2f(x, y),
                            sf::Vector2f(width,  height), type);
  sf::Texture& texture = *m_resources->getResource(id);
  sf::IntRect tilePlacement{0,0,32,32};
  m_tiles.push_back(tempTile);
  setTileTexture(index, texture);
  setTextureRect(index, tilePlacement);
}
bool TileManager::setTileTexture(int index, const sf::Texture &texture) {
  //TODO: CHECK IF EVERYTHING IS OK TO RETURN TRUE
  m_tiles[index]->getSprite().setTexture(texture);
  return true;
}

void TileManager::update(float dt, float ups){
  for (auto& tile : m_tiles){
    tile->update(dt,ups);
  }
}
void TileManager::draw(sf::RenderWindow& window){
  for (auto& tile : m_tiles){
    tile->draw(window);
  }

}
void TileManager::setTextureRect(int index, sf::IntRect& rect){
  if (m_tiles[index]){
    m_tiles[index]->getSprite().setTextureRect(rect);
  }
}
