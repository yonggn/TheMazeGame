#include "EntityManager.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace sf;

namespace Engine
{
    void EntityManager::LoadTexture(string name, string fileName)
    {
        Texture tex;

        if(tex.loadFromFile(fileName))
        {
            this->_textures[name]=tex;
        }
    }

    Texture &EntityManager::GetTexture(string name)
    {
        return this->_textures.at(name);
    }

    void EntityManager::LoadFont(string name, string fileName)
    {
        Font font;

        if(font.loadFromFile(fileName))
        {
            this->_fonts[name]=font;
        }
    }

    Font &EntityManager::GetFont(string name)
    {
        return this->_fonts.at(name);
    }

}


