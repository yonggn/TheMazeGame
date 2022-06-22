#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Roulant.h"
#include "Elf.h"
#include "State.h"
#include "GameManager.h"
#include "Definition.h"
#include "Maze.h"


using namespace std;
using namespace sf;

namespace Engine
{

    class GameMec: public State, Maze
    {
        public:
            //hud
            Font font;
            Text live;
            Text score;
            Text highestScore;

            int highestScr;
            int scr = 0; //score and fight count will be initialised when every game start

            bool lvlComplete=false;

            float dt = (1.0f / 60.0f);
            float timer = 0.0f; //timer for input
            float timere=0.0f; //timer for elf movement
            float timerev = 0.0f;//timer for collision event

            bool elfDie=false;

            Sprite smaze[20][20];


        public:
            Roulant *roulant;
            Elf *elf;
            Elf *elf1;
            Elf *elf2;
            Elf *elf3;
            Sprite trap;
            Sprite statue;
            Sprite wall;
            Sprite floor;

            GameMec(GameDataRef data);
            ~GameMec(){}

            void Init();
            void HandleInput();
            void Update(float deltaTime);
            void Draw(float deltaTime);

        private:
            GameDataRef _data;
    };
}

