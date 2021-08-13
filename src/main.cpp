/* System Headers */
#include <iostream>

/* 3rd-Party */
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "Game.hpp"


int main() {
    Game app;
    app.init("Title", 800, 600);
    app.run();
    return 0;
}

