#include "../../include/Managers/SceneManager.hpp"

SceneManager::SceneManager() {

}
SceneManager::~SceneManager() {

}

void SceneManager::init() {
    addScene(new GameScene(this));
}

void SceneManager::addScene(Scene* l_scene) {
    if( l_scene ) {
        m_scenes.emplace(l_scene);
        m_currentScene = m_scenes.top();
    }
}

void SceneManager::deleteScene(uint32_t l_ID) {

}

void SceneManager::nextScene() {

}
void SceneManager::previousScene() {

}

void SceneManager::handleInput(sf::Event e) {
    if (!m_currentScene){
        return;
    }
    m_currentScene->handleInput(e);


}
void SceneManager::render(sf::RenderWindow& window) {
    if (!m_currentScene){
        return;
    }
    m_currentScene->render(window);

}
void SceneManager::update(float dt, float ups) {
    if (!m_currentScene){
        return;
    }
    m_currentScene->update(dt,ups);
}
