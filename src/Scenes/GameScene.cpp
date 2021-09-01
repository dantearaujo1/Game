#include "../../include/Scenes/GameScene.hpp"
#include "../../include/Managers/SceneManager.hpp"

GameScene::GameScene(SceneManager *manager) : Scene(manager) {}
GameScene::~GameScene() { m_director = nullptr; }

bool GameScene::init() {
  const auto entity = m_entityManager.create();
  const auto entity2 = m_entityManager.create();

  auto &cposition = m_entityManager.emplace<PositionComponent>(entity, 400, 300);
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

  if (e.key.code == sf::Keyboard::Space) {
  }
  if (e.key.code == sf::Keyboard::R) {
  }
  if (e.key.code == sf::Keyboard::E) {
  }
  if (e.key.code == sf::Keyboard::Q) {
  }
}
void GameScene::render(sf::RenderWindow &window) {

  auto view = m_entityManager.view<SpriteComponent>();
  for (auto entity : view) {
    window.draw(view.get<SpriteComponent>(entity).sprite);
  }
}
void GameScene::update(float dt, float ups) {
  auto view = m_entityManager.view<PositionComponent, SpriteComponent, ControllerComponent, AnimationComponent, MovementComponent>();
  for (auto entity : view) {

    auto &playersprite = view.get<SpriteComponent>(entity).sprite;
    auto &pos = view.get<PositionComponent>(entity);
    auto &con = view.get<ControllerComponent>(entity);
    auto &ani = view.get<AnimationComponent>(entity);
    auto &mov = view.get<MovementComponent>(entity);
    /* auto &states = view.get<StateComponent>(entity); */

    mov.velx = 0;
    mov.vely = 0;
    // Like Animation System
    ani.currentFrameDuration += dt;
    if (ani.currentFrameDuration >= ani.frameDuration){
      ani.currentFrameDuration = 0;
      if (ani.currentFrame <  ani.frames[ani.currentFrameString].size()-1){
        ani.currentFrame += 1;
      }
      else{
        ani.currentFrame = 0;
      }
    }
    playersprite.setTextureRect(ani.frames[ani.currentFrameString][ani.currentFrame]);

    if (sf::Keyboard::isKeyPressed(con.keys["Left"])) {
      /* pos.y = 0; */
      /* pos.x = -5 * dt; */
      mov.velx = -5;
      ani.currentFrameString = "Left";
    }
    if (sf::Keyboard::isKeyPressed(con.keys["Right"])) {
      /* pos.y = 0; */
      /* pos.x = +5 * dt; */
      mov.velx = 5;
      ani.currentFrameString = "Right";
    }
    if (sf::Keyboard::isKeyPressed(con.keys["Up"])) {
      /* pos.x = 0; */
      /* pos.y = -5 * dt; */
      mov.vely = -5;
      ani.currentFrameString = "Up";
    }
    if (sf::Keyboard::isKeyPressed(con.keys["Down"])) {
      /* pos.x = 0; */
      /* pos.y = +5 * dt; */
      mov.vely = 5;
      ani.currentFrameString = "Down";
    }
    playersprite.setPosition(pos.x,pos.y);
  }
  m_mSystem.update(dt,ups);
}
