#include "../../include/Managers/SceneManager.hpp"
#include "../../include/Scenes/GameScene.hpp"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {
  while (!m_scenes.empty()){
    deleteScene();
  }
}

void SceneManager::init() {
  m_textures.setDirectory("../assets/textures/");
  loadResources();
  addScene(new GameScene(this));
}

void SceneManager::loadResources() {
  m_textures.loadFromFile("map", "rpg tileset/b_map.png");
  m_textures.loadFromFile("male", "male_sprite_model.png");
  m_textures.loadFromFile("female", "female_sprite_model.png");
  m_textures.loadFromFile("child", "child_sprite_model.png");
  m_textures.loadJokerfromFile("joker.png");
}
void SceneManager::addScene(Scene *l_scene) {
  if (l_scene) {
    m_scenes.emplace(l_scene);
    m_currentScene = m_scenes.top();
    m_currentScene->init();
  }
}

void SceneManager::deleteScene() {
  delete m_scenes.top();
  m_scenes.pop();
  if(!m_scenes.empty())
  {
    m_currentScene = m_scenes.top();
  }
}

void SceneManager::nextScene() {}
void SceneManager::previousScene() {}

void SceneManager::handleInput(sf::Event e) {
  if (!m_currentScene) {
    return;
  }
  m_currentScene->handleInput(e);
}
void SceneManager::render(sf::RenderWindow &window) {
  if (!m_currentScene) {
    return;
  }
  m_currentScene->render(window);
}
void SceneManager::update(float dt, float ups) {
  if (!m_currentScene) {
    return;
  }
  m_currentScene->update(dt, ups);
}
