#include "Scene.hpp"

#include "../vendors/entt/entt.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../Managers/AnimationManager.hpp"
#include "../Managers/TileManager.hpp"
#include "../ECS/Systems/AnimationSystem.hpp"
#include "../ECS/Systems/ControllerSystem.hpp"
#include "../ECS/Systems/MovementSystem.hpp"
#include "../ECS/Systems/RenderSystem.hpp"
#include "../EntityFactory.hpp"

#include <iostream>

class GameScene : public Scene {

public:
  GameScene(SceneManager *manager);
  ~GameScene();

  bool init();
  bool loadAnimations();
  void handleInput(sf::Event e);
  void render(sf::RenderWindow &window);
  void update(float dt, float ups);

private:
  void setFrameRect(int row, int column);

  entt::registry m_entityManager{};

  AnimationFactory m_aFactory;
  TileManager m_tileManager;
  EntityFactory m_eFactory{&m_entityManager,m_director,&m_aFactory};
  MovementSystem m_mSystem{&m_entityManager};
  ControllerSystem m_cSystem{&m_entityManager};
  AnimationSystem m_aSystem{&m_entityManager};
  RenderSystem m_rSystem{&m_entityManager};
};
