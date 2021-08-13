#include "../../include/Scenes/MenuScene.hpp"

MenuScene::MenuScene(SceneManager* manager) : Scene(manager){

}
MenuScene::~MenuScene(){
    m_director = nullptr;
}

void MenuScene::handleInput(sf::Event e){

}
void MenuScene::render(sf::RenderWindow& window){
    window.clear(sf::Color::Black);
}
void MenuScene::update(float dt, float ups){

}
