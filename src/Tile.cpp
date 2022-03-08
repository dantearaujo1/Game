#include "../include/Tile.hpp"

Tile::Tile(sf::Vector2f position, sf::Vector2f size, TILETYPE type) : m_position(position), m_size(size), m_type(type){

}
Tile::~Tile(){

}

void Tile::update(float dt, float ups){
  m_sprite.setPosition(m_position);
}

void Tile::draw(sf::RenderWindow& window){
  window.draw(m_sprite);
}
