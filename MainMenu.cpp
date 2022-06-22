#include "MainMenu.h"
#include "Definition.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "SplashState.h"
#include "Credit.h"

using namespace sf;
using namespace std;

namespace Engine
{
    MainMenu::MainMenu(GameDataRef data): _data(data)
    {

    }
    void MainMenu::Init()
    {
        this->_data->assets.LoadFont("Menu Font",FONT_FILEPATH);
        // Title
        _gameTitle.setFont(this->_data->assets.GetFont("Menu Font"));
        _gameTitle.setString("The Maze Game");
        _gameTitle.setCharacterSize(60);
        _gameTitle.setPosition((SCREEN_WIDTH/2)-(this->_gameTitle.getGlobalBounds().width/2),(SCREEN_HEIGHT/2)- (this->_gameTitle.getGlobalBounds().height/3)-250.f);
        _gameTitle.setFillColor(Color::Yellow);

         // Play Button
        menu[0].setFont(this->_data->assets.GetFont("Menu Font"));
        menu[0].setString("Play");
        menu[0].setFillColor(Color::Red);
        menu[0].setOrigin(menu[0].getLocalBounds().width / 2,menu[0].getLocalBounds().height / 2);
        menu[0].setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2-100.f);
        menu[0].setCharacterSize(30);

        // Credit Button
        menu[1].setFont(this->_data->assets.GetFont("Menu Font"));
        menu[1].setString("Credit");
        menu[1].setFillColor(Color::White);
        menu[1].setOrigin(menu[1].getLocalBounds().width / 2,menu[1].getLocalBounds().height / 2);
        menu[1].setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2 );
        menu[1].setCharacterSize(30);

        // Exit Button
        menu[2].setFont(this->_data->assets.GetFont("Menu Font"));
        menu[2].setString("Exit");
        menu[2].setFillColor(Color::White);
        menu[2].setOrigin(menu[2].getLocalBounds().width / 2,menu[2].getLocalBounds().height / 2);
        menu[2].setPosition(this->_data->window.getSize().x / 2 , this->_data->window.getSize().y / 2 + 100.f);
        menu[2].setCharacterSize(30);

        tex.loadFromFile("Assets/Interface/Control.png");
        control.setTexture(tex);
        control.setPosition((SCREEN_WIDTH/4)-200.f,(SCREEN_HEIGHT/2)- (this->control.getGlobalBounds().height/3)+100.f);
        control.setScale(0.5f,0.5f);

        selected =0;

    }

    void MainMenu::HandleInput()
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
                    case Keyboard::W:
                        up=true;
                        down=false;
                        break;
                    case Keyboard::S:
                        down=true;
                        up=false;
                        break;
                    case Keyboard::Return:
                    {
                        switch(selected)
                        {
                        case 0:
                            cout<<"Play"<<endl;
                            this->_data->stateManager.AddState(StateRef (new SplashState(_data)),true);  //lvl 1 story
                            break;
                        case 1:
                            cout<<"Credit"<<endl;
                            this->_data->stateManager.AddState(StateRef (new Credit(_data)),true);
                            break;
                        case 2:
                            this->_data->window.close();

                        }
                    break;
                    }
                }
            }
        }
    }

    void MainMenu::Update(float dt)
    {
        if(up)
        {
            if(selected-1>=0)
        {
            menu[selected].setFillColor(Color::White);
            selected--;
            menu[selected].setFillColor(Color::Red);
        }
        up=false;
        }
        if(down)
        {
            if(selected+1<3)
        {
            menu[selected].setFillColor(Color::White);
            selected++;
            menu[selected].setFillColor(Color::Red);
        }
        down=false;
        }
    }

    void MainMenu::Draw(float dt)
    {
        this->_data->window.clear(Color::Black);
        this->_data->window.draw(control);
        this->_data->window.draw(_gameTitle);
        for(int i=0;i<3;i++)
        {
            this->_data->window.draw(menu[i]);
        }
        this->_data->window.display();
    }
}









