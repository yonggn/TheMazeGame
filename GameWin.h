#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include "Definition.h"
#include "GameManager.h"
#include "MainMenu.h"

using namespace sf;
using namespace std;


namespace Engine
{
    class GameWin:public State
    {
        public:
            GameWin(GameDataRef data):_data(data){}


            void Init()
            {
                _data->assets.LoadTexture("GameWinScreen",GAME_WIN_SCREEN_FILEPATH);
                gamewin.setTexture(this->_data->assets.GetTexture("GameWinScreen"));
                gamewin.setScale(0.46,0.50);
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
                            case Keyboard::C:
                               _data->stateManager.AddState(StateRef(new MainMenu(this->_data)),true);
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
                this->_data->window.draw(gamewin);
                this->_data->window.display();
            }

        protected:

        private:
            GameDataRef _data;
            Sprite gamewin;
    };
}


