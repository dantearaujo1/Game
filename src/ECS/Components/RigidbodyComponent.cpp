#include "../include/ECS/Components/RigidbodyComponent.hpp"

RigidbodyComponent::RigidbodyComponent() : m_rect(sf::FloatRect(0.0f,0.0f,32.0f,32.0f)) , m_aceleration(sf::Vector2f(0.0f,0.0f))
{

}
RigidbodyComponent::RigidbodyComponent(float x, float y, sf::Vector2f size , sf::Vector2f aceleration)
{
  m_rect = sf::FloatRect(x,y, size.x, size. y);
  m_aceleration = aceleration;
}


RigidbodyComponent::~RigidbodyComponent()
{
}

