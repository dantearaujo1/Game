#pragma once

#include "ResourceManager.hpp"
#include "../Tools/TextureHelper.hpp"
#include "../Tile.hpp"

#include "SFML/Graphics.hpp"

#include <vector>

class TileManager
{
public:
  TileManager(ResourceManager<sf::Texture>* resources);
  TileManager(TileManager &&) = default;
  TileManager(const TileManager &) = default;
  TileManager &operator=(TileManager &&) = default;
  TileManager &operator=(const TileManager &) = default;
  ~TileManager();

  void createTile(int texLoc, float x = 0, float y = 0, float width = 32.0f, float height = 32.0f, const std::string& id = "map", TILETYPE type = TILETYPE::NONE);
  bool setTileTexture(int index, const sf::Texture& texture );
  void setTextureRect(int index, sf::IntRect rect);
  void update(float dt, float ups);
  void draw(sf::RenderWindow& window);

private:
  ResourceManager<sf::Texture>* m_resources;
  std::vector<Tile*> m_tiles;
  TextureHelper m_helper;
};


