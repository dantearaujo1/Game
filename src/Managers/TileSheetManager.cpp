#include "../include/Managers/TileSheetManager.hpp"
#include "../include/Game.hpp"

TileSheetManager::TileSheetManager() : m_app(nullptr), m_textureResources(nullptr), m_currentTileSheet(nullptr)
{
}

TileSheetManager::~TileSheetManager()
{
}

void TileSheetManager::init(Game* app){
  if(!m_app){
    m_app = app;
  }
  if (m_textureResources){
    m_textureResources = static_cast<SceneManager*>(app->getDirector())->getTextureManager();
  }
}
void TileSheetManager::update(float dt, float ups){

}

void TileSheetManager::addTileSheet(const std::string &path, const std::string& id){
  m_textureResources->loadFromFile(path,id);
  m_tileSheets.push_back(id);
}
void TileSheetManager::setTileSheet(const std::string id){
  m_currentTileSheet = m_textureResources->getResource(id);
}
sf::Texture *TileSheetManager::getTileSheet(const std::string id){
  return m_textureResources->getResource(id);
}
