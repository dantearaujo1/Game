#include "Scene.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../vendors/entt/entt.hpp"
#include "../ECS/Systems/MovementSystem.hpp"

#include <iostream>

class GameScene : public Scene {

public:
  GameScene(SceneManager *manager);
  ~GameScene();

  bool init();
  void handleInput(sf::Event e);
  void render(sf::RenderWindow &window);
  void update(float dt, float ups);

private:
  void setFrameRect(int row, int column);

  entt::registry  m_entityManager;
  MovementSystem  m_mSystem{&m_entityManager};
};
