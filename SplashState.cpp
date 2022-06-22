#include "SplashState.h"
#include "Definition.h"
#include "GameMec.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    SplashState::SplashState(GameDataRef data): _data(data)
    {

    }

    void SplashState::Init()
    {
        this->_data->assets.LoadTexture("Prologue",PROLOGUE_SCREEN_FILEPATH);
        this->_data->assets.LoadTexture("Prologue Start",PROLOGUE_START_SCREEN_FILEPATH);

        _scene[0].setTexture(this->_data->assets.GetTexture("Prologue"));
        _scene[1].setTexture(this->_data->assets.GetTexture("Prologue Start"));

        _scene[0].setScale(0.46,0.46);
        _scene[1].setScale(0.46,0.46);


    }

    void SplashState::HandleInput()
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

    void SplashState::Update(float dt)
    {


    }

    void SplashState::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene[0]);
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->window.draw(_scene[1]);
            if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME*2)
            {
                this->_data->stateManager.AddState(StateRef (new GameMec(this->_data)),true);
                cout<<"ToGame";
            }
        }
        this->_data->window.display();
    }



}


