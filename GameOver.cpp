/*#include "GameOver.h"
#include "GameMec.h"
#include "EntityManager.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

GameOver::GameOver(shared_ptr<Context> &context)
    : m_context(context), retry(false), exit(false)
{

}

GameOver::~GameOver()
{
    //dtor
}

void GameOver::Init()
{
    m_context->m_assets->AddTexture(GAMELOSE, "Assets/Interface/You died.png");
    gameover.setTexture(m_context->m_assets->GetTexture(GAMELOSE));
}

void GameOver::ProcessInput()
{
    Event event;
    while(m_context->m_window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            m_context->m_window->close();
        }
        else if (event.type == Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case Keyboard::R:
            retry=true;
            break;
            case Keyboard::Escape:
            exit=true;
            break;
            default:
                break;
            }
        }
    }
}

void GameOver::Update()
{
    if(retry)
        m_context->m_states->Add(make_unique<GameMec>(m_context),true);
    else if (exit)
        m_context->m_window->close();
}

void GameOver::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(gameover);
    m_context->m_window->display();
}*/
