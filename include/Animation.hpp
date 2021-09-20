#pragma once

#include "SFML/Graphics.hpp"


struct Animation {
  Animation(){};
  std::vector<sf::IntRect> frames;
  sf::Texture* texture{nullptr}; // WARN: This is okay? have a text in animation?
  float duration{2.0f};
  float currentDuration{0};
  int currentFrame{0};
  bool repeat{true};
  bool reverse{true};
};
