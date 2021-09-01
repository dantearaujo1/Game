#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"

#include "Managers/SceneManager.hpp"

class Game {

public:
  Game();
  ~Game();

  void init(const std::string &title, uint32_t width, uint32_t height);
  void run();

private:
  void handleInput();
  void render();
  void update(float dt, float ups);

  sf::RenderWindow m_window;
  SceneManager m_sceneManager;
  sf::Clock m_clock;
  sf::Event m_event;
  sf::Time m_gameTime;
  sf::Time m_deltaTime;
};
