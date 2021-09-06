#include "../../include/Scenes/GameScene.hpp"
#include "../../include/Managers/SceneManager.hpp"

GameScene::GameScene(SceneManager *manager) : Scene(manager) {}
GameScene::~GameScene() { m_director = nullptr; }

bool GameScene::init() {
  const auto entity = m_entityManager.create();
  const auto entity2 = m_entityManager.create();

  auto &cposition = m_entityManager.emplace<PositionComponent>(entity, 400, 300);
  auto &cstates = m_entityManager.emplace<StateComponent>(entity);
  auto &cmovement = m_entityManager.emplace<MovementComponent>(entity);
  cmovement.velx = 5;
  cmovement.vely = 5;

  auto &scomponent = m_entityManager.emplace<SpriteComponent>(entity);
  scomponent.sprite.setTexture(*m_director->getTexture("child"));
  scomponent.sprite.setTextureRect(sf::IntRect(2 * 32, 1 * 64, 32, 64));
  scomponent.sprite.setPosition(cposition.x,cposition.y);

  auto& ccontroller = m_entityManager.emplace<ControllerComponent>(entity);
  ccontroller.keys["Left"] = sf::Keyboard::A;
  ccontroller.keys["Right"] = sf::Keyboard::D;
  ccontroller.keys["Down"] = sf::Keyboard::S;
  ccontroller.keys["Up"] = sf::Keyboard::W;

  /* auto& cstates = m_entityManager.emplace<StateComponent>(entity); */

  auto& canimation = m_entityManager.emplace<AnimationComponent>(entity);
  canimation.frameDuration = 2.8f;
  canimation.currentFrameDuration = 0.0f;

  std::vector<sf::IntRect> frames;
  for (int i = 0; i <= 4;i++){
    frames.push_back(sf::IntRect(i*32,0,32,64));
  }
  canimation.frames["Up"] = frames;

  std::vector<sf::IntRect> frames1;
  for (int i = 0; i <= 4;i++){
    frames1.push_back(sf::IntRect(i*32,64,32,64));
  }
  canimation.frames["Down"] = frames1;

  std::vector<sf::IntRect> frames2;
  for (int i = 0; i <= 7;i++){
    frames2.push_back(sf::IntRect(i*32,128,32,64));
  }
  canimation.frames["Right"] = frames2;

  std::vector<sf::IntRect> frames3;
  for (int i = 0; i <= 7;i++){
    frames3.push_back(sf::IntRect(i*32,192,32,64));
  }
  canimation.frames["Left"] = frames3;

  canimation.currentFrameString = "Down";
  canimation.currentFrame = 0;

  return true;
}
void GameScene::handleInput(sf::Event e) {
  m_cSystem.handleInput(e);
}
void GameScene::render(sf::RenderWindow &window) {
  m_rSystem.render(window);

}
void GameScene::update(float dt, float ups) {
  m_cSystem.update(dt,ups);
  m_mSystem.update(dt,ups);

  // Systems that update Render to window something
  m_rSystem.update(dt,ups);
  m_aSystem.update(dt,ups);
}
