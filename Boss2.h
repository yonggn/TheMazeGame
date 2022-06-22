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
     class Boss2
    {
        public:
            int posX,posY;
            Sprite boss;
            int bossFight=0;
            bool bossAttack=false;
            bool bossDie=false;
            float timer;
            float dt=1.f/60.f;
            int moveNow;
            IntRect rect;
            IntRect attackrect;


            Boss2(GameDataRef data) : _data(data)
            {
                cout<<"Loading Boss\n";
                attackrect = {0,97,63,97};
                rect = {0,0,63,97};
                boss.setTexture(_data->assets.GetTexture("BossButler"));
                cout<<"Loading Elf Texture\n";
                boss.setTextureRect(rect);
                cout<<"Loading Elf Texture Rect\n";
                //elf.setScale(0.15f,0.15f);
                cout<<"Loading Elf Scale\n";
                bossAni(rect);
                cout<<"Loading Elf Ani\n";
                moveNow=0;
                cout<<"Loading Elf Random Move\n";
            }

            void Draw()
            {
                _data->window.draw(boss);
            }

            void UpdateBossAni()
            {
                if(bossAttack==true)
                {
                    bossAni(attackrect);
                }
                if(bossDie)
                {
                    bossFight+=1;
                    if(bossFight==3)
                    {
                        boss.setScale(0.0f,0.0f);
                    }
                }
                else
                {
                    bossAni(rect);
                }
            }

            void bossAni(IntRect &rect)
            {
                timer+=dt;
                if (timer>0.1f)
                {
                    if(!bossDie)
                    {
                        rect.left+=63;
                        // set the sprite maximum x value after each tick
                        if (rect.left==126)
                        {
                            rect.left=0;
                        }
                    }
                    else
                    {
                        rect.left+=63;
                    }
                    // set the steps for x-value in each tick
                    //else{
                    //    r.left+=63;
                    //}
                    //cout<<r.left;
                    boss.setTextureRect(rect);
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
                            boss.move(0,-30);
                            posY--;
                        }
                        break;
                    case 1:
                        if(Maze[posY][posX+1] !='w' && Maze[posY-1][posX] !='t'&&Maze[posY-1][posX] !='b' && Maze[posY-1][posX] !='s' && Maze[posY-1][posX] !='e'  && posX < 20-1)
                        {
                            boss.move(40,0);
                            posX++;
                        }
                        break;
                    case 2:
                        if(Maze[posY+1][posX] !='w' && Maze[posY-1][posX] !='t'&&Maze[posY-1][posX] !='b' && Maze[posY-1][posX] !='s' && Maze[posY-1][posX] !='e' && posY < 20-1)
                        {
                            boss.move(0,30);
                            posY++;
                        }
                        break;
                    case 3:
                        if(Maze[posY][posX+1] !='w' && Maze[posY-1][posX] !='t'&&Maze[posY-1][posX] !='b' && Maze[posY-1][posX] !='s' && Maze[posY-1][posX] !='e'  && posX < 20-1)
                        {
                            boss.move(40,0);
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
                return boss;
            }

        protected:

        private:
            GameDataRef _data;
    };

}

