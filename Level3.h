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
#include "Boss1.h"


using namespace std;
using namespace sf;

namespace Engine
{

    class Level3: public State, Maze
    {
        public:
            Font font;
            Text live;
            Text score;
            Text highestScore;

            int highestScr=0;
            int scr = 0; //score and fight count will be initialised when every game start

            bool lvlComplete=false;

            float dt = (1.0f / 60.0f);
            float timer = 0.0f; //timer for input
            float timere=0.0f; //timer for elf movement
            float timerev = 0.0f;

            bool elfDie=false;

            Sprite smaze[20][20];


        public:

            Roulant *roulant;
            Elf *elf;
            Elf *elfr;
            Elf *elfu;
            Elf *elfp;
            Elf *elfl;
            Elf *elfj;
            Elf *elfa;
            Elf *elfi;
            Elf *elfo;
            Boss1* boss1;
            Sprite trap;
            Sprite statue;
            Sprite wall;
            Sprite floor;

            Level3(GameDataRef data);
            ~Level3(){}

            void Init();
            void HandleInput();
            void Update(float deltaTime);
            void Draw(float deltaTime);

        private:
            GameDataRef _data;
    };



}

