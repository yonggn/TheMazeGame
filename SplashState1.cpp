#include "SplashState1.h"
#include "Definition.h"
#include "Level2.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    SplashState1::SplashState1(GameDataRef data): _data(data)
    {}

    void SplashState1::Init()
    {
        this->_data->assets.LoadTexture("Level2",LEVEL2_SCREEN_FILEPATH);
        this->_data->assets.LoadTexture("Level2 Start",LEVEL2_START_SCREEN_FILEPATH);

        _scene[0].setTexture(this->_data->assets.GetTexture("Level2"));
        _scene[1].setTexture(this->_data->assets.GetTexture("Level2 Start"));

        _scene[0].setScale(0.46,0.46);
        _scene[1].setScale(0.46,0.46);
    }

    void SplashState1::HandleInput()
    {
        Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }
    }

    void SplashState1::Update(float dt)
    {}

    void SplashState1::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene[0]);
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->window.draw(_scene[1]);
            if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME*2)
            {
                this->_data->stateManager.AddState(StateRef (new Level2(_data)),true);
                cout<<"ToLevel2";
            }
        }
        this->_data->window.display();
    }



}


