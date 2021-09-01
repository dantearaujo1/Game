#pragma once
#include <stack>

#include "../Managers/ResourceManager.hpp"
#include "../Scenes/Scene.hpp"
#include "SFML/Graphics.hpp"

class SceneManager {
public:
  SceneManager();
  ~SceneManager();

  void init();
  void loadResources();

  void addScene(Scene *l_scene);
  void deleteScene();

  void nextScene();
  void previousScene();

  sf::Texture *getTexture(const std::string &id) {
    return m_textures.getResource(id);
  }

  void handleInput(sf::Event e);
  void render(sf::RenderWindow &window);
  void update(float dt, float ups);

private:
  std::stack<Scene *> m_scenes;
  Scene *m_currentScene;
  ResourceManager<sf::Texture> m_textures;
};
