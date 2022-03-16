#include <string>
#include <iostream>

#include "SFML/Graphics.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

class Manager;

class Game {

public:
  Game();
  ~Game();

  void init(const std::string &title, uint32_t width, uint32_t height);
  void run();
  bool isDebugActivated() const { return m_debug; }
  void setDebug(bool tf) { m_debug = tf; }
  Manager* getDirector() { return m_sceneManager; }

private:
  void handleInput();
  void render();
  void update(float dt, float ups);

  sf::RenderWindow m_window;
  Manager* m_sceneManager;
  bool m_debug;
  sf::Clock m_clock;
  sf::Event m_event;
  sf::Time m_gameTime;
  sf::Time m_deltaTime;
};
