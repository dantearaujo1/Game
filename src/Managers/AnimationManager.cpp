#include "../../include/Managers/AnimationManager.hpp"

AnimationManager::AnimationManager(){

}
AnimationManager::~AnimationManager(){
  while (!m_animations.empty()){
    for (std::map<int,Animap>::iterator itr = m_animations.begin(); itr != m_animations.end(); itr++){
      for (Animap::iterator it = itr->second.begin(); it != itr->second.end();it++){
          delete it->second;
          it->second = nullptr;
      }

    }
  }
}
void AnimationManager::addFrame(Animation& animation, sf::IntRect frame){
  animation.frames.push_back(frame);
}
void AnimationManager::addTexture(Animation& animation, sf::Texture& texture){
  animation.texture = &texture;
}
bool AnimationManager::hasAnimation(int entityID, std::pair<StateComponent::STATUS,StateComponent::DIRECTION> state){
  if (m_animations.find(entityID) != m_animations.end()){
    if(m_animations[entityID].find(state) != m_animations[entityID].end()){
      return true;
    }
    return false;
  }
  return false;

}
void AnimationManager::setState(){

}
Animation* AnimationManager::getAnimation(){
  return nullptr;
}


