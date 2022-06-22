#include "SplashState3.h"
#include "Definition.h"
#include "Level4.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    SplashState3::SplashState3(GameDataRef data): _data(data)
    {

    }

    void SplashState3::Init()
    {

        this->_data->assets.LoadTexture("Level4",LEVEL4_SCREEN_FILEPATH);
        this->_data->assets.LoadTexture("Level4 Start",LEVEL4_START_SCREEN_FILEPATH);
        _scene[0].setTexture(this->_data->assets.GetTexture("Level4"));
        _scene[1].setTexture(this->_data->assets.GetTexture("Level4 Start"));

        _scene[0].setScale(0.46,0.46);
        _scene[1].setScale(0.46,0.46);
    }

    void SplashState3::HandleInput()
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

    void SplashState3::Update(float dt){}

    void SplashState3::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene[0]);
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->window.draw(_scene[1]);
            if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME*2)
            {
                this->_data->stateManager.AddState(StateRef (new Level4(_data)),true);
                cout<<"ToLevel4";
            }
        }
        this->_data->window.display();
    }



}


