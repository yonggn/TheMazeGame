#include "Credit.h"
#include "Definition.h"
#include "GameManager.h"
#include "GameMec.h"
#include "MainMenu.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

namespace Engine
{
    Credit::Credit(GameDataRef data): _data(data)
    {

    }

    void Credit::Init()
    {
        this->_data->assets.LoadTexture("Credit",CREDIT_SCREEN_FILEPATH);
        this->_data->assets.LoadFont("Press esc",FONT_FILEPATH);
        _scene.setTexture(this->_data->assets.GetTexture("Credit"));
        _scene.setScale(0.45,0.45);
        text.setFont(_data->assets.GetFont("Press esc"));
        text.setString("Press escape to Main Menu");
        text.setScale(0.5,0.5);
        text.setPosition((SCREEN_WIDTH/2)-(this->text.getGlobalBounds().width/2),(SCREEN_HEIGHT/2)- (this->text.getGlobalBounds().height/3)+250.f);

    }

    void Credit::HandleInput()
    {
        Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            else if(Event::KeyPressed == event.type)
            {
                switch (event.key.code)
                {
                    case Keyboard::Escape:
                    this->_data->stateManager.AddState(StateRef(new MainMenu(this->_data)),true);
                    break;
                }
            }

        }
    }

    void Credit::Update(float dt)
    {


    }

    void Credit::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(_scene);
        this->_data->window.draw(text);
        this->_data->window.display();
    }



}
