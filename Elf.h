#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Definition.h"
#include "GameManager.h"

using namespace sf;
using namespace std;

namespace Engine
{
     class Elf
    {
        public:
            int posX,posY;
            Sprite elf;
            bool elfDie=false;
            float timer;
            float dt=1.f/60.f;
            int moveNow;
            IntRect rect;
            IntRect drect;


            Elf(GameDataRef data) : _data(data)
            {
                cout<<"Loading Elf\n";
                drect = {0,64,32,32};
                rect = {0,0,32,32};
                elf.setTexture(_data->assets.GetTexture("Elf"));
                cout<<"Loading Elf Texture\n";
                elf.setTextureRect(rect);
                cout<<"Loading Elf Texture Rect\n";
                //elf.setScale(0.15f,0.15f);
                cout<<"Loading Elf Scale\n";
                elfAni(rect);
                cout<<"Loading Elf Ani\n";
                moveNow=0;
                cout<<"Loading Elf Random Move\n";
            }

            void Draw()
            {
                _data->window.draw(elf);
            }

            void UpdateElfAni()
            {
                if(elfDie==true)
                {
                    elfAni(drect);
                    elfDie=false;
                }
                else
                {
                    elfAni(rect);
                }
            }

            void elfAni(IntRect &rect)
            {
                timer+=dt;
                if (timer>0.1f)
                {
                    if(!elfDie)
                    {
                        rect.left+=32;
                        // set the sprite maximum x value after each tick
                        if (rect.left==160)
                        {
                            rect.left=0;
                        }
                    }
                    else
                    {
                        rect.left+=32;
                    }
                    // set the steps for x-value in each tick
                    //else{
                    //    r.left+=63;
                    //}
                    //cout<<r.left;
                    elf.setTextureRect(rect);
                    timer=0.0f;

                }

            }


            void randomMove(int choice, char Maze[20][20])
            {
                if(moveNow)
                {
                    switch(choice)
                    {
                    case 0:
                        if(Maze[posY-1][posX] !='w' && Maze[posY-1][posX] !='t'&&Maze[posY-1][posX] !='b' && Maze[posY-1][posX] !='s' && Maze[posY-1][posX] !='e'  && posY-1 > 0)
                        {
                            elf.move(0,-30);
                            posY--;
                        }
                        break;
                    case 1:
                        if(Maze[posY][posX+1] !='w' && Maze[posY-1][posX] !='t'&&Maze[posY-1][posX] !='b' && Maze[posY-1][posX] !='s' && Maze[posY-1][posX] !='e'  && posX < 20-1)
                        {
                            elf.move(40,0);
                            posX++;
                        }
                        break;
                    case 2:
                        if(Maze[posY+1][posX] !='w' && Maze[posY-1][posX] !='t'&&Maze[posY-1][posX] !='b' && Maze[posY-1][posX] !='s' && Maze[posY-1][posX] !='e' && posY < 20-1)
                        {
                            elf.move(0,30);
                            posY++;
                        }
                        break;
                    case 3:
                        if(Maze[posY][posX+1] !='w' && Maze[posY-1][posX] !='t'&&Maze[posY-1][posX] !='b' && Maze[posY-1][posX] !='s' && Maze[posY-1][posX] !='e'  && posX < 20-1)
                        {
                            elf.move(40,0);
                            posX++;
                        }
                        break;
                    }
                    moveNow = 0;
                }
                else
                {
                    moveNow = 1;
                }
            }

            const Sprite &GetSprite() const
            {
                return elf;
            }

        protected:

        private:
            GameDataRef _data;



            //const char Maze[][20];


    };

}

