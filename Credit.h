#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameManager.h"

using namespace sf;
using namespace std;

namespace Engine
{
    class Credit : public State
    {
    public:
        Credit(GameDataRef data);

        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        Clock _clock;
        Sprite _scene;
        bool backToMenu = false;
        Font font;
        Text text;
    };
}
