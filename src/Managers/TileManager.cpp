#include "../include/Managers/TileManager.hpp"

#include "../include/Game.hpp"

TileManager::TileManager(Game *app, ResourceManager<sf::Texture> *manager)
    : m_resources(manager),
      m_helper(sf::Vector2i(32.0f, 32.0f),
               sf::Vector2i(m_resources->getResource("map")->getSize())),
      m_map(nullptr),
      m_app(app) {
  m_tileTypeMapHelper = {
      {TILETYPE::NONE, "None"},   {TILETYPE::WALL, "Wall"},
      {TILETYPE::FLOOR, "Floor"}, {TILETYPE::WATER, "Water"},
      {TILETYPE::SAND, "Sand"},   {TILETYPE::GRASS, "Grass"},
      {TILETYPE::ICE, "Ice"},
  };
  m_tileSheetManager.init(app);
  m_map = new tinytmx::Map();
}

TileManager::~TileManager() {
  int i = m_tiles.size() - 1;
  while(!m_tiles.empty()){
    while (!m_tiles[i].empty()) {
      Tile *forDelete = m_tiles[i].back();
      delete forDelete;
      forDelete = nullptr;
      m_tiles[i].pop_back();
    }
    m_tiles.pop_back();
  }
  delete m_map;
  m_map = nullptr;
}

void TileManager::init(Game *app) {
  if (!m_app)
    m_app = app;
  m_tileTypeMapHelper = {
      {TILETYPE::NONE, "None"},   {TILETYPE::WALL, "Wall"},
      {TILETYPE::FLOOR, "Floor"}, {TILETYPE::WATER, "Water"},
      {TILETYPE::SAND, "Sand"},   {TILETYPE::GRASS, "Grass"},
      {TILETYPE::ICE, "Ice"},
  };
  m_tileSheetManager.init(app);
  m_map = new tinytmx::Map();
  m_map->ParseFile("D:/Code/Languages/C++/Projects/Breakout/assets/map/map.tmx");

  for (int i = 0; i < m_map->GetNumLayers(); i++){
    std::vector<Tile*> temp;
    m_tiles.push_back(temp);
  }
  std::cout << m_tiles.size() << std::endl;

}
void TileManager::handleInput(sf::Event e) {}

void TileManager::createTile(int layer, int texLoc, float x, float y, float width,
                             float height, const std::string &id,
                             TILETYPE type) {

    int index = m_tiles[layer].size();
    Tile *tempTile =
        new Tile(sf::Vector2f(x, y), sf::Vector2f(width, height), type);
    m_tiles[layer].push_back(tempTile);
    sf::Texture &texture = *m_resources->getResource(m_map->GetTileset(0)->GetName());
    setTileTexture(index, texture,layer);
    setTextureRect(index, m_helper.getTileByID(texLoc),layer);
}

bool TileManager::setTileTexture(int index, const sf::Texture &texture, int layer) {
  // TODO: CHECK IF EVERYTHING IS OK TO RETURN TRUE
  m_tiles[layer][index]->getSprite().setTexture(texture);
  return true;
}

void TileManager::update(float dt, float ups){
  for (auto &layer : m_tiles) {
    for (auto& tile: layer){
      tile->update(dt, ups);
    }
  }
}
void TileManager::render(sf::RenderWindow &window) {
  if(m_map->GetNumLayers() > 4){
    for (int i = 0; i < 4; i++){

      for( auto& tiles : m_tiles[i]){
        tiles->draw(window);
      }
    }
  }
  else{
    for(auto& layers : m_tiles){
      for (auto& tiles : layers){
        tiles->draw(window);
      }
    }

  }
}
void TileManager::renderAfter(sf::RenderWindow &window){

    //Drawing tiles after Player
    for(int i = 4; i < m_tiles.size(); i++){
      for (auto& tiles : m_tiles[i]){
        tiles->draw(window);
      }
    }
    //DEBUGGIN
    for (auto& tiles : m_tiles[0]){
      // tiles->draw(window);
      if (m_app->isDebugActivated()) {
        sf::RectangleShape debugTile;
        debugTile.setPosition(tiles->getPosition());
        debugTile.setFillColor(sf::Color::Transparent);
        debugTile.setOutlineColor(sf::Color::Red);
        debugTile.setOutlineThickness(1);
        debugTile.setSize(sf::Vector2f(m_map->GetTileWidth(),m_map->GetTileHeight()));
        window.draw(debugTile);
      }
    }

}
void TileManager::setTextureRect(int index, sf::IntRect rect, int layer) {
  if (m_tiles[layer][index]) {

    TILETYPE tp = m_tiles[layer][index]->getType();

    m_tiles[layer][index]->getSprite().setTextureRect(rect);
  }
}

// Load a Map from a file
bool TileManager::loadFromFile(const std::string& file){
  return true;
}
