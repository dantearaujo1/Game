#pragma once
#include "SFML/Graphics.hpp"

class SceneManager;
class Scene
{
    public:
        Scene(SceneManager* manager) {m_director = manager;} ;
        virtual ~Scene(){};

        virtual bool init() = 0;
        virtual void handleInput(sf::Event e) = 0;
        virtual void render(sf::RenderWindow& window) = 0;
        virtual void update(float dt, float ups) = 0;

    protected:

        SceneManager* m_director;

};
