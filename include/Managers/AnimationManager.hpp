#include "../ECS/Components/Components.hpp"
#include <map>


class AnimationManager{

  public:
    AnimationManager();
    ~AnimationManager();

    void addFrame(Animation& animation, sf::IntRect frame);
    void addTexture(Animation& animation, sf::Texture& texture);
    bool hasAnimation(int entityID, std::pair<StateComponent::STATUS,StateComponent::DIRECTION> state);
    void setState();
    Animation* getAnimation();

  private:

  typedef std::map<std::pair<StateComponent::STATUS,StateComponent::DIRECTION>,Animation*> Animap;
  std::map<int,Animap> m_animations;

};
