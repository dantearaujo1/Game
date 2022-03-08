#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>

struct FrameData{
  FrameData(){};
  float duration;
  std::string id;
  sf::IntRect frame;
};

struct Animation {
  Animation(){};
  std::vector<FrameData*> framesData;
  int currentFrame{0};
  float currentDuration{0};
};
