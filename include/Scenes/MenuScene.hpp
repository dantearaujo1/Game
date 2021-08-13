#pragma once
#include "Scene.hpp"

class MenuScene : public Scene {

    public:
        MenuScene(SceneManager* manager);
        virtual ~MenuScene();

        virtual void handleInput(sf::Event e);
        virtual void render(sf::RenderWindow& window);
        virtual void update(float dt, float ups);
    private:

};
