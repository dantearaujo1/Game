#pragma once

#include "../Animation.hpp"
#include <map>


class AnimationFactory{

  public:
    AnimationFactory();
    ~AnimationFactory();

    Animation* createAnimation(const std::string& ID);
    Animation* getAnimation(const std::string& ID);
    bool hasAnimation(const std::string& ID);
    void addFrames(const std::string& ID, int frames, int x, int y, int width, int height, bool horizontal=true);

  private:
    void addFrame(const std::string& ID, sf::IntRect frame, float duration=2.0f);

    std::map<const std::string, Animation*> m_animations;

};
