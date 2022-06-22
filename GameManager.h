#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "EntityManager.h"
#include "StateManager.h"

using namespace sf;
using namespace std;

namespace Engine
{
    struct GameData
    {
        StateManager stateManager;
        RenderWindow window;
        EntityManager assets;

    };

    typedef shared_ptr<GameData> GameDataRef;

    class Game
    {
    private:
        const float dt=1.0f/60.0f;
        Clock _clock;

        GameDataRef _data = make_shared<GameData>();
        void Run();
    public:
        Game(int width,int height, string title);
        Music gameMusic;

    };
}

