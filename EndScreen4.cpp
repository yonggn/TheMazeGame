#include "EndScreen4.h"
#include "Definition.h"
#include "GameWin.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    EndScreen4::EndScreen4(GameDataRef data, int score, int highestScore): _data(data),_score(score),_highestScore(highestScore)
    {

    }

    void EndScreen4::Init()
    {
        cout<<"end scene\n";
        this->_data->assets.LoadTexture("5EndScreen",LEVEL5_END_SCREEN_FILEPATH);
        this->_data->assets.LoadTexture("EEndScreen",EPILOGUE_SCREEN_FILEPATH);
        this->_data->assets.LoadTexture("EEndScreen Start",EPILOGUE_START_SCREEN_FILEPATH);

        _scene[0].setTexture(this->_data->assets.GetTexture("5EndScreen"));
        _scene[1].setTexture(this->_data->assets.GetTexture("EEndScreen"));
        _scene[2].setTexture(this->_data->assets.GetTexture("EEndScreen Start"));

        _scene[0].setScale(0.46,0.46);
        _scene[1].setScale(0.46,0.46);
        _scene[2].setScale(0.46,0.46);

        font.loadFromFile("Assets/Fonts/BOD_B.ttf");
        gameWin.setFont(font);
        yourScore.setFont(font);
        yourHighestScore.setFont(font);

        gameWin.setCharacterSize(50);
        yourScore.setCharacterSize(30);
        yourHighestScore.setCharacterSize(30);

        gameWin.setPosition(this->_data->window.getSize().x / 2-100.f, this->_data->window.getSize().y / 2-100.f);
        yourScore.setPosition(this->_data->window.getSize().x / 2-100.f, this->_data->window.getSize().y / 2);
        yourHighestScore.setPosition(this->_data->window.getSize().x / 2-100.f, this->_data->window.getSize().y / 2+100.f);

        gameWin.setString("YOU WIN");
        yourScore.setString("Your score : "+ to_string(_score));
        yourHighestScore.setString("Your highest score : "+ to_string(_highestScore));

        gameWin.setColor(Color::Yellow);
        yourScore.setColor(Color::White);
        yourHighestScore.setColor(Color::White);
    }

    void EndScreen4::HandleInput()
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

    void EndScreen4::Update(float dt)
    {}

    void EndScreen4::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene[0]);
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->window.draw(_scene[1]);
            if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME*2)
            {
                this->_data->window.draw(_scene[2]);
                if(this->_clock.getElapsedTime().asSeconds()>SPLASH_STATE_SHOW_TIME*3)
                {
                    this->_data->window.clear(Color::Black);
                    this->_data->window.draw(gameWin);
                    this->_data->window.draw(yourScore);
                    this->_data->window.draw(yourHighestScore);
                    if(this->_clock.getElapsedTime().asSeconds()>SPLASH_STATE_SHOW_TIME*4)
                    {
                        this->_data->stateManager.AddState(StateRef (new GameWin(this->_data)),true);
                        cout<<"ToWinScreen";
                    }
                }
            }
        }
        this->_data->window.display();
    }



}

