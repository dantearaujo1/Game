#pragma once


#include "Components.hpp"

class RigidbodyComponent
{
public:
  RigidbodyComponent();
  RigidbodyComponent(float x, float y, sf::Vector2f size = sf::Vector2f(32.0f,32.0f), sf::Vector2f aceleration = sf::Vector2f(0.0f,0.0f));
  RigidbodyComponent(RigidbodyComponent &&) = default;
  RigidbodyComponent(const RigidbodyComponent &) = default;
  RigidbodyComponent &operator=(RigidbodyComponent &&) = default;
  RigidbodyComponent &operator=(const RigidbodyComponent &) = default;
  ~RigidbodyComponent();

  

private:
    sf::FloatRect m_rect;
    sf::Vector2f m_aceleration;
    friend class PhysicsSystem;
};


