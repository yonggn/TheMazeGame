#include "StateManager.h"
#include <iostream>

using namespace std;

namespace Engine
{
    void StateManager::AddState(StateRef newState, bool isReplacing)
    {
        this-> _isAdding=true;
        this->_isReplacing=isReplacing;
        this->_newState=move(newState);
    }

    void StateManager::RemoveState()
    {
        this-> _isRemoving=true;
        cout<<"Removing state\n";
    }

    void StateManager::ProcessStateChange()
    {
        if(this->_isRemoving && ! this->_states.empty())
        {
            this->_states.pop();
            if(this->_states.empty())
            {
                this->_states.top()->Resume();
            }
            this->_isRemoving=false;
        }

        if(this->_isAdding)
        {
            cout<<"Adding state\n";
            if(!this->_states.empty())
            {
                if(this->_isReplacing)
                {
                    this->_states.pop();
                    cout<<"Popping the state\n";
                }
                else
                    this->_states.top()->Pause();
                    cout<<"Pausing state\n";
            }
            this->_states.push(move(this->_newState));
            this->_states.top()->Init();
            this->_isAdding=false;
        }
    }

    StateRef &StateManager::GetCurrentState()
    {
        return this->_states.top();
    }
}
