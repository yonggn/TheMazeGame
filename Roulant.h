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
    class Roulant
    {
        public:
            int posX,posY;
            Sprite roulant;
            Sprite aroulant;
            bool playerOuch = false;
            bool isAttack=false;
            bool canMove=true;
            int lives=3; //lives will be reset every game start
            int direction = 0;
            IntRect moveUp;
            IntRect moveDown;
            IntRect moveLeft;
            IntRect moveRight;
            IntRect hurt;
            SoundBuffer attB;
            Sound att;


            Roulant(GameDataRef data) : _data(data)
            {
                moveUp = {0,0,63,64};
                moveDown= {0,128,63,64};
                moveLeft= {0,64,63,64};
                moveRight= {0,192,63,64};
                hurt = {0,256,63,64};

                cout<<"Loading Roulant\n";
                IntRect rect(0,128,63,64);
                roulant.setTexture(this->_data->assets.GetTexture("Player"));
                cout<<"Loading Roulant Texture\n";
                roulant.setTextureRect(rect);
                cout<<"Setting Roulant Texture Rect\n";
                roulant.setScale(1.0,1.0);
                cout<<"Setting Roulant Scale\n";
                roulant.setPosition(posX*35,posY*25);
                cout<<"SettingRoulant Position\n";

                attB.loadFromFile("Assets/Music/kiang.wav");
                att.setBuffer(attB);

            }

            void Draw()
            {
                _data->window.draw(roulant);
            }

            void moving(char dir, char Maze[20][20])
            {
                    if(dir =='L')
                    {
                        if(Maze[posY][posX-1] !='w' && posX-1 >0 )
                        {
                            cout<<"move left";
                            roulant.move(-40,0);
                            posX--;
                        }
                        direction = 1;

                    }
                    if(dir=='R')
                    {

                        if(Maze[posY][posX+1] !='w' && posX < 20-1)
                        {
                            cout<<"move right";
                            roulant.move(40,0);
                            posX++;
                        }
                        direction = 2;
                    }
                    if(dir=='U')
                    {

                        if(Maze[posY-1][posX] !='w' && posY-1 > 0)
                        {
                            cout<<"move up";
                            roulant.move(0,-30);
                            posY--;
                        }
                        direction = 3;
                    }
                    if(dir=='D')
                    {
                        if(Maze[posY+1][posX] !='w' && posY < 20-1)
                        {
                            cout<<"move down";
                            roulant.move(0,30);
                            posY++;
                        }
                        direction = 4;
                    }
                   if(dir=='A')
                   {
                           att.play();
                   }
            }

            void UpdateAnimation()
            {
                if (direction == 1)
                {
                    aniR(moveLeft);
                }
                else if (direction == 2)
                {
                   aniR(moveRight);
                }
                else if (direction == 3)
                {
                   aniR(moveUp);
                }
                else if(direction == 4)
                {
                   aniR(moveDown);
                }
                if(playerOuch == true)
                {
                    aniR(hurt);
                }
            }

            void aniR(IntRect &r)
            {
                timer+=dt;
                if (timer>0.08f)
                {
                    if(playerOuch==true)
                    {
                        r.left+=63;
                        if(r.left==252)
                            playerOuch=false;
                    }
                    else
                    {

                        r.left+=63;
                        // set the sprite maximum x value after each tick
                        if (r.left==441){
                            r.left=0;
                        }
                        cout<<r.left;
                        // set the steps for x-value in each tick
                    }
                    roulant.setTextureRect(r);
                    timer=0.0f;

                }
            }


            const Sprite &GetSprite() const
            {
                return roulant;
            }

        protected:

        private:
            GameDataRef _data;

            int rl=0;
            float dt=1.0f/60.0f;
            float timer=0.0f;

    };
}



