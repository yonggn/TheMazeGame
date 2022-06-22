#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include "State.h"
#include "GameManager.h"

using namespace sf;
using namespace std;

namespace Engine
{
    class MainMenu : public State
    {
    private:
        GameDataRef _data;

        Text _gameTitle;
        Text menu[3];

        int selected;

        bool up=false;
        bool down=false;

        Texture tex;
        Sprite control;


    public:
        MainMenu(GameDataRef data);


        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    };
}



