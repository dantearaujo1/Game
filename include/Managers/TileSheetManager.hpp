#pragma once

#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "SFML/Graphics.hpp"

class TileSheetManager : public Manager {
public:
  TileSheetManager();
  ~TileSheetManager();

  void init(Game *app) override;
  void update(float dt, float ups) override;
  void render(sf::RenderWindow &window) override{};
  void handleInput(sf::Event e) override{};

  void addTileSheet(const std::string &path, const std::string& id);
  void setTileSheet(const std::string id);
  sf::Texture *getCurrentTileSheet() { return m_currentTileSheet; };
  sf::Texture *getTileSheet(const std::string id);

  sf::Vector2u getCurrentTileSheetSize() const { return m_currentTileSheet->getSize(); }

private:
  Game *m_app;
  ResourceManager<sf::Texture>* m_textureResources;
  std::vector<std::string> m_tileSheets;
  sf::Texture *m_currentTileSheet;
};
