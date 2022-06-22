#pragma once
#include <SFML/System/Time.hpp>

using namespace std;
using namespace sf;

namespace Engine
{
    class State
    {
    public:
        State(){};
        virtual ~State(){};

        virtual void Init() = 0;
        virtual void HandleInput() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Draw(float deltaTime) = 0;

        virtual void Pause(){};
        virtual void Resume(){};
    };

}
