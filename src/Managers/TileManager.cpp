#include "../include/Managers/TileManager.hpp"

#include "../include/Game.hpp"

TileManager::TileManager(Game *app, ResourceManager<sf::Texture> *manager)
    : m_resources(manager),
      m_helper(sf::Vector2i(32.0f, 32.0f),
      sf::Vector2i(m_resources->getResource("map")->getSize())),
      m_app(app) {}

TileManager::~TileManager() {}
void TileManager::init(Game* app) {if(!m_app) m_app=app;}
void TileManager::handleInput(sf::Event e) {}

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
void TileManager::render(sf::RenderWindow &window) {
  for (auto &tile : m_tiles) {
    tile->draw(window);
    if (m_app->isDebugActivated()) {
      sf::RectangleShape debugTile;
      debugTile.setPosition(tile->getPosition());
      debugTile.setFillColor(sf::Color::Transparent);
      debugTile.setOutlineColor(sf::Color::Red);
      debugTile.setOutlineThickness(1);
      debugTile.setSize(tile->getSize());
      window.draw(debugTile);
    }
  }
}
void TileManager::setTextureRect(int index, sf::IntRect rect) {
  if (m_tiles[index]) {

    TILETYPE tp = m_tiles[index]->getType();

    m_tiles[index]->getSprite().setTextureRect(rect);
  }
}
