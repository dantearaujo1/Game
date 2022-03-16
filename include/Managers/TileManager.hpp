#pragma once

#include "../Tile.hpp"
#include "../Tools/TextureHelper.hpp"
#include "Manager.hpp"
#include "ResourceManager.hpp"
#include "TileSheetManager.hpp"

#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "tinytmx.hpp"

#include <vector>

// This class should only take care of the map of the Game and nothing else
class TileManager : public Manager {
public:
  TileManager(Game *app = nullptr,
              ResourceManager<sf::Texture> *resources = nullptr);
  TileManager(TileManager &&) = default;
  TileManager(const TileManager &) = default;
  TileManager &operator=(TileManager &&) = default;
  TileManager &operator=(const TileManager &) = default;
  ~TileManager();

  void init(Game *app) override;
  void handleInput(sf::Event e) override;
  void update(float dt, float ups) override;
  void render(sf::RenderWindow &window) override;
  void renderAfter(sf::RenderWindow &window) ;

  const std::string& getStringTileType(TILETYPE type) {
    return m_tileTypeMapHelper[type];
  };

  tinytmx::Map* getMap() { return m_map; }

  void createTile(int layer, int texLoc, float x = 0, float y = 0, float width = 32.0f,
                  float height = 32.0f, const std::string &tilesheet = "map",
                  TILETYPE type = TILETYPE::NONE);

  bool setTileTexture(int index, const sf::Texture &texture, int layer = 0);
  void setTextureRect(int index, sf::IntRect rect, int layer = 0);

  // TODO: Load a map from a file
  bool loadFromFile(const std::string& file);

  TextureHelper &getTextureHelper() { return m_helper; }
  Tile *getTile(int id, int layer = 0) { return m_tiles[layer][id]; }

private:
  std::map<TILETYPE, const std::string> m_tileTypeMapHelper;
  ResourceManager<sf::Texture> *m_resources;
  TileSheetManager m_tileSheetManager;
  std::vector<std::vector<Tile *>> m_tiles;
  TextureHelper m_helper;
  tinytmx::Map* m_map;
  Game *m_app;
};
