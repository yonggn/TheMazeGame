#include "EndScreen1.h"
#include "Definition.h"
#include "SplashState2.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    EndScreen1::EndScreen1(GameDataRef data, int score, int highestScore): _data(data),_score(score),_highestScore(highestScore)
    {

    }

    void EndScreen1::Init()
    {
        cout<<"end scene\n";
        this->_data->assets.LoadTexture("2EndScreen",LEVEL2_END_SCREEN_FILEPATH);
        _scene.setTexture(this->_data->assets.GetTexture("2EndScreen"));
        _scene.setScale(0.46,0.46);

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

    void EndScreen1::HandleInput()
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

    void EndScreen1::Update(float dt)
    {


    }

    void EndScreen1::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene);
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->window.clear(Color::Black);
            this->_data->window.draw(gameWin);
            this->_data->window.draw(yourScore);
            this->_data->window.draw(yourHighestScore);
            if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME*2)
            {
                this->_data->stateManager.AddState(StateRef (new SplashState2(this->_data)),true);
                cout<<"ToLevel3Splash\n";
            }
        }

        this->_data->window.display();
    }



}

