#include "SplashState2.h"
#include "Definition.h"
#include "Level3.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    SplashState2::SplashState2(GameDataRef data): _data(data)
    {

    }

    void SplashState2::Init()
    {

        this->_data->assets.LoadTexture("Level3",LEVEL3_SCREEN_FILEPATH);
        this->_data->assets.LoadTexture("Level3 Start",LEVEL3_START_SCREEN_FILEPATH);
        _scene[0].setTexture(this->_data->assets.GetTexture("Level3"));
        _scene[1].setTexture(this->_data->assets.GetTexture("Level3 Start"));
        _scene[0].setScale(0.46,0.46);
        _scene[1].setScale(0.46,0.46);
    }

    void SplashState2::HandleInput()
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

    void SplashState2::Update(float dt)
    {


    }

    void SplashState2::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene[0]);
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->window.draw(_scene[1]);
            if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME*2)
            {
                this->_data->stateManager.AddState(StateRef (new Level3(this->_data)));
                cout<<"ToLevel3";
            }
        }
        this->_data->window.display();
    }



}


