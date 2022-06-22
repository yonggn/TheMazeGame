#pragma once
#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Maze.h"

using namespace sf;
using namespace std;

namespace Engine
{
    class EntityManager
    {
        public:
            EntityManager(){}
            ~EntityManager(){}

            void LoadTexture(string name,string fileName);
            Texture &GetTexture(string name);

            void LoadFont(string name,string fileName);
            Font &GetFont(string name);

        private:
            map<string, Texture> _textures;
            map<string, Font> _fonts;

    };
} // namespace Engine
