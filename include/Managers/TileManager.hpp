#pragma once

#include "ResourceManager.hpp"
#include "Manager.hpp"
#include "../Tools/TextureHelper.hpp"
#include "../Tile.hpp"

#include "imgui.h"
#include "SFML/Graphics.hpp"

#include <vector>

class TileManager : public Manager
{
public:
  TileManager(Game* app = nullptr, ResourceManager<sf::Texture>* resources = nullptr);
  TileManager(TileManager &&) = default;
  TileManager(const TileManager &) = default;
  TileManager &operator=(TileManager &&) = default;
  TileManager &operator=(const TileManager &) = default;
  ~TileManager();

  void init(Game* app) override;
  void handleInput(sf::Event e) override;
  void update(float dt, float ups) override;
    void render(sf::RenderWindow& window) override;


  void createTile(int texLoc, float x = 0, float y = 0, float width = 32.0f, float height = 32.0f, const std::string& id = "map", TILETYPE type = TILETYPE::NONE);
  bool setTileTexture(int index, const sf::Texture& texture );
  void setTextureRect(int index, sf::IntRect rect);
  TextureHelper& getTextureHelper() { return m_helper; }

private:
  ResourceManager<sf::Texture>* m_resources;
  std::vector<Tile*> m_tiles;
  TextureHelper m_helper;
  Game* m_app;
};


