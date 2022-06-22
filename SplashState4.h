#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameManager.h"

using namespace sf;
using namespace std;

namespace Engine
{
    class SplashState4 : public State
    {
    public:
        SplashState4(GameDataRef data);

        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        Clock _clock;
        Sprite _scene[2];
    };
}
