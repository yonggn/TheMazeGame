#include "GameManager.h"
#include "MainMenu.h"

using namespace std;
using namespace sf;

namespace Engine
{
    Game::Game(int width, int height, string title)
    {
        _data->window.create(VideoMode(width,height),title,Style::Close|Style::Titlebar);
        _data->stateManager.AddState(StateRef(new MainMenu(this->_data)));
        this->Run();
    }

    void Game::Run()
    {
        gameMusic.openFromFile("Assets/Music/Dalabengba.wav");
        gameMusic.setVolume(10);
        gameMusic.play();
        gameMusic.setLoop(true);
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator=0.0f;
        while (this->_data->window.isOpen())
        {
            this->_data->stateManager.ProcessStateChange();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime=newTime-currentTime;

            if(frameTime>0.25f)
            {
                frameTime=0.25f;
            }
            currentTime=newTime;
            accumulator +=frameTime;

            while(accumulator>=dt)
            {
                this->_data->stateManager.GetCurrentState()->HandleInput();
                this->_data->stateManager.GetCurrentState()->Update(dt);
                accumulator-=dt;
            }
            interpolation = accumulator/dt;
            this->_data->stateManager.GetCurrentState()->Draw(interpolation);


        }
    }
}
