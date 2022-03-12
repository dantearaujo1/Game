#pragma once

// #include "../include/Game.hpp"
#include "SFML/Graphics.hpp"
class Game;


class Manager
{
public:
  virtual ~Manager(){};

  Game* getApp() const { return m_app; }
  virtual void init(Game* app) =0;
  virtual void update(float dt, float ups) = 0;
  virtual void render(sf::RenderWindow& windo) {};
  virtual void handleInput(sf::Event e) {};

protected:

  Game* m_app;
};

