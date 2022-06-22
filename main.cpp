#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "GameManager.h"
#include "Definition.h"

using namespace sf;
using namespace std;


int main()
{
    Engine::Game(SCREEN_WIDTH,SCREEN_HEIGHT,"The Maze Game");
    srand(time(NULL)); //so that enemy can move in different pattern

    return EXIT_SUCCESS;
}

