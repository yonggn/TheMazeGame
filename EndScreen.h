#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameManager.h"


using namespace sf;
using namespace std;

namespace Engine
{
    class EndScreen : public State
    {
    public:
        EndScreen(GameDataRef data,int score,int highestScore);

        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        Font font;
        Text gameWin;
        Text yourScore;
        Text yourHighestScore;

        GameDataRef _data;
        Clock _clock;
        Sprite _scene;

        int _score;
        int _highestScore;
    };
}
