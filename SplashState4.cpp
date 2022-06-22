#include "SplashState4.h"
#include "Definition.h"
#include "FinalLevel.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    SplashState4::SplashState4(GameDataRef data): _data(data)
    {}

    void SplashState4::Init()
    {
        this->_data->assets.LoadTexture("Level5",LEVEL5_SCREEN_FILEPATH);
        this->_data->assets.LoadTexture("Level5 Start",LEVEL5_START_SCREEN_FILEPATH);

        _scene[0].setTexture(this->_data->assets.GetTexture("Level5"));
        _scene[1].setTexture(this->_data->assets.GetTexture("Level5 Start"));

        _scene[0].setScale(0.46,0.46);
        _scene[1].setScale(0.46,0.46);
    }

    void SplashState4::HandleInput()
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

    void SplashState4::Update(float dt)
    {}

    void SplashState4::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene[0]);
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->window.draw(_scene[1]);
            if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME*2)
            {
                this->_data->stateManager.AddState(StateRef (new FinalLevel(this->_data)),true);
                cout<<"ToLevel5";
            }
        }
        this->_data->window.display();
    }



}


