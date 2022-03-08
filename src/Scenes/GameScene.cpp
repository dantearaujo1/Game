#include "../../include/Scenes/GameScene.hpp"
#include "../../include/Managers/SceneManager.hpp"

#include <iterator>
#include <type_traits>
#include <utility>
// #include <iostream>

GameScene::GameScene(SceneManager *manager) : Scene(manager), m_tileManager(m_director->getTextureManager()) {
}
GameScene::~GameScene() { m_director = nullptr; }

bool GameScene::init() {

  m_aSystem.textureManager = m_director;
  if(!loadAnimations()){
    return false;
  }
  m_eFactory.createPlayer(1);
  m_eFactory.createPlayer(2);
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 25; j++){
      m_tileManager.createTile(j*32,i*32,32,32,"map", TILETYPE::FLOOR);
    }
  }

  return true;
}
void GameScene::handleInput(sf::Event e) { m_cSystem.handleInput(e); }
void GameScene::render(sf::RenderWindow &window) {
  m_tileManager.draw(window);
  m_rSystem.render(window);
}
void GameScene::update(float dt, float ups) {
  m_cSystem.update(dt, ups);
  m_mSystem.update(dt, ups);

  // Systems that update Render to window something
  m_tileManager.update(dt,ups);
  m_rSystem.update(dt, ups);
  m_aSystem.update(dt, ups);
}
bool GameScene::loadAnimations(){
  m_aFactory.createAnimation("child_walking_left");
  m_aFactory.createAnimation("child_walking_right");
  m_aFactory.createAnimation("child_walking_north");
  m_aFactory.createAnimation("child_walking_south");

  m_aFactory.addFrames("child_walking_north", 5, 0,0,32,64);
  m_aFactory.addFrames("child_walking_south", 5, 0,64,32,64);
  m_aFactory.addFrames("child_walking_left", 8, 0,128,32,64);
  m_aFactory.addFrames("child_walking_right", 8, 0,192,32,64);

  return true;
}
