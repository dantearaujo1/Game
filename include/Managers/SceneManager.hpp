#pragma once
#include <stack>

#include "Manager.hpp"
#include "../Managers/ResourceManager.hpp"
#include "../Scenes/Scene.hpp"



class SceneManager : public Manager {
public:
  SceneManager(Game* app = nullptr);
  ~SceneManager();

  void init(Game* app);
  void loadResources();
  ResourceManager<sf::Texture>* getTextureManager(){return &m_textures;}

  void addScene(Scene *l_scene);
  void deleteScene();

  void nextScene();
  void previousScene();

  Game* getApp() { return m_app; }

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
  Game* m_app;
};

