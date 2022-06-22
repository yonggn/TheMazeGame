#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Definition.h"
#include "GameManager.h"
#include "Level3.h"

using namespace sf;
using namespace std;

namespace Engine
{
    class GameOver2: public State
    {
        private:
            GameDataRef _data;
            Sprite gameover;

            bool retry=false;
            bool exit;
        public:
            GameOver2(GameDataRef data):_data(data){}


            void Init()
            {
                _data->assets.LoadTexture("GameOverScreen",GAME_LOSE_SCREEN_FILEPATH);
                gameover.setTexture(this->_data->assets.GetTexture("GameOverScreen"));
                gameover.setScale(0.46,0.50);
            }
            void HandleInput()
            {
                Event event;
                while (this->_data->window.pollEvent(event))
                {
                    if (Event::Closed==event.type)
                    {
                    this->_data->window.close();
                    }
                    else if (Event::KeyPressed == event.type)
                    {
                        switch (event.key.code)
                        {
                            case Keyboard::R:
                               this->_data->stateManager.AddState(StateRef(new Level3(this->_data)),true);
                            break;

                        }
                    }
                }
            }
            void Update(float deltaTime)
            {

            }
            void Draw(float deltaTime)
            {
                this->_data->window.clear(Color::Black);
                this->_data->window.draw(gameover);
                this->_data->window.display();
            }

        protected:


    };
}
