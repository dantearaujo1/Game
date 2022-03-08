#include "../../include/Managers/AnimationManager.hpp"

AnimationFactory::AnimationFactory(){

}

AnimationFactory::~AnimationFactory(){
  while (!m_animations.empty()){
    for (std::map<const std::string,Animation*>::iterator itr = m_animations.begin(); itr != m_animations.end(); itr++){
      while (!itr->second->framesData.empty()){

        if (!itr->second->framesData.back()) continue;
        FrameData* pointer = itr->second->framesData.back();
        itr->second->framesData.pop_back();

        delete pointer;
        pointer = nullptr;
      }
      delete itr->second;
      itr->second = nullptr;
    }
  }
}

void AnimationFactory::addFrame(const std::string& ID, sf::IntRect frame, float duration){
  if (hasAnimation(ID)){
    FrameData* temp = new FrameData();
    temp->id = ID;
    temp->duration = duration;
    temp->frame = frame;
    m_animations[ID]->framesData.push_back(temp);
  }
  return;
}

Animation* AnimationFactory::createAnimation(const std::string& ID){

  auto iterator = m_animations.find(ID);

  if (iterator != m_animations.end()){
    return m_animations[ID];
  }

  Animation* memory = new Animation();
  m_animations[ID]= memory;
  return m_animations[ID];

}

Animation* AnimationFactory::getAnimation(const std::string& ID){
  if (hasAnimation(ID)){
    return m_animations[ID];
  }
  return nullptr;
}

bool AnimationFactory::hasAnimation(const std::string& ID){
  auto iterator = m_animations.find(ID);
  if (iterator != m_animations.end()){
    return true;
  }
  return false;
}


void AnimationFactory::addFrames(const std::string& ID, int frames, int x, int y, int width, int height, bool horizontal){
  if(hasAnimation(ID)){
    for (int i = 0; i < frames; i++){
      FrameData* tempdata = new FrameData();
      tempdata->duration =2.0f;
      tempdata->id =ID;
      if (horizontal){
        tempdata->frame = sf::IntRect( x+width*i,y,width,height );
      }
      else{
        tempdata->frame = sf::IntRect( x,y+height*i,width,height );
      }
      Animation* anim = getAnimation(ID);
      anim->framesData.push_back(tempdata);
    }
  }
}

