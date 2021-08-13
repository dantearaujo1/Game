#pragma once
#include <stack>

#include "../Scenes/GameScene.hpp"
#include "../Scenes/MenuScene.hpp"
#include "SFML/Graphics.hpp"

class SceneManager {
public:
  SceneManager();
  ~SceneManager();

  void init();

  void addScene(Scene *l_scene);
  void deleteScene(uint32_t l_ID);

  void nextScene();
  void previousScene();

  void handleInput(sf::Event e);
  void render(sf::RenderWindow &window);
  void update(float dt, float ups);

private:
  std::stack<Scene *> m_scenes;
  Scene *m_currentScene;
};
