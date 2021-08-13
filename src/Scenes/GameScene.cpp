#include "../../include/Scenes/GameScene.hpp"

GameScene::GameScene(SceneManager* manager) : Scene(manager){

}
GameScene::~GameScene(){
    m_director = nullptr;
}


void GameScene::handleInput(sf::Event e){
    /* if (m_event.key.code == sf::Keyboard::Space) { */
    /*     m_shape.setFillColor(sf::Color::Yellow); */
    /* } */
    /* if (m_event.key.code == sf::Keyboard::R) { */
    /*     m_shape.setFillColor(sf::Color::Red); */
    /* } */
    /* if (m_event.key.code == sf::Keyboard::E) { */
    /*     m_shape_width+= 5.0f; */
    /*     m_shape_height+= 5.0f; */
    /*     m_shape.setSize(sf::Vector2f(m_shape_width, m_shape_height)); */
    /* } */
    /* if (m_event.key.code == sf::Keyboard::Q) { */
    /*     m_shape_width -= 5.0f; */
    /*     m_shape_height -= 5.0f; */
    /*     m_shape.setSize(sf::Vector2f(m_shape_width, m_shape_height)); */
    /* } */

}
void GameScene::render(sf::RenderWindow& window){
    window.clear(sf::Color::Green);
}
void GameScene::update(float dt, float ups){
    /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { */
    /*     m_shape.move(sf::Vector2f(-5.0f * dt, 0.0f * dt)); */
    /* } */
    /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { */
    /*     m_shape.move(sf::Vector2f(+5.0f * dt, 0.0f * dt)); */
    /* } */
    /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { */
    /*     m_shape.move(sf::Vector2f(0.0f * dt, -5.0f * dt)); */
    /* } */
    /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { */
    /*     m_shape.move(sf::Vector2f(0.0f * dt, 5.0f * dt)); */
    /* } */

}
