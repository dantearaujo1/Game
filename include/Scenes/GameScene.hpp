#pragma once
#include "Scene.hpp"

class GameScene : public Scene {

    public:
        GameScene(SceneManager* manager);
        ~GameScene();

        void handleInput(sf::Event e);
        void render(sf::RenderWindow& window);
        void update(float dt, float ups);
    private:

};
