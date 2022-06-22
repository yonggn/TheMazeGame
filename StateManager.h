#pragma once
#include <stack>
#include <memory>
#include "State.h"

using namespace sf;
using namespace std;

namespace Engine
{
    typedef unique_ptr<State> StateRef;

    class StateManager
    {
    public:
    StateManager(){}
    ~StateManager(){}

    void AddState(StateRef newState, bool isReplace = false);
    void RemoveState();

    void ProcessStateChange();

    StateRef &GetCurrentState();

    private:
        stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };

}
