#include "Level4.h"
#include "GameOver3.h"
#include "EndScreen3.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Maze.h"
#include "GameManager.h"
#include "Definition.h"
#include "Roulant.h"
#include "Elf.h"
#include "Boss2.h"

using namespace std;
using namespace sf;

namespace Engine
{
    Level4::Level4(GameDataRef data): _data(data)
    {
        scr=0;
    }

    void Level4::Init()
    {
        ifstream readFile;
        readFile.open("Assets/PlayerData/HighestScoreLevel4.txt");
        if(readFile.is_open())
        {
            while(!readFile.eof())
            {
                readFile>> highestScr;
            }
        }
        readFile.close();

        cout<<"Loading level\n";
        _data->assets.LoadTexture("Wall", WALL_TEXTURE_FILEPATH);
        cout <<"Wall Texture Loaded\n";
        _data->assets.LoadTexture("Floor", FLOOR_TEXTURE_FILEPATH);
        cout <<"Floor Texture Loaded\n";
        _data->assets.LoadTexture("Trap", TRAP_TEXTURE_FILEPATH);
        cout <<"Trap Texture Loaded\n";
        _data->assets.LoadTexture("Statue", STATUE_TEXTURE_FILEPATH);
        cout <<"Status Texture Loaded\n";
        _data->assets.LoadTexture("Player", ROULANT_TEXTURE_FILEPATH);
        cout <<"Player Texture Loaded\n";
        _data->assets.LoadTexture("Player Attack", ROULANT_ATTACK_TEXTURE_FILEPATH);
        cout <<"Player Attack Texture Loaded\n";
        _data->assets.LoadTexture("Elf","Assets/Character/elf.png");
        cout <<"Elf Texture Loaded\n";
         _data->assets.LoadTexture("BossButler",BOSS3_TEXTURE_FILEPATH);
         cout<<"Boss Butler loaded";
        font.loadFromFile(FONT_FILEPATH);
        cout <<"Font Loaded\n";
        cout << "Complete Loading\n";

        roulant = new Roulant(_data);
        elf = new Elf(_data);
        elfm = new Elf(_data);
        elfy = new Elf(_data);
        elfl = new Elf(_data);
        elfv = new Elf(_data);
        elfa = new Elf(_data);
        elfp = new Elf(_data);
        elfo = new Elf(_data);
        elfj = new Elf(_data);
        elfu = new Elf(_data);
        elfi = new Elf(_data);
        boss2= new Boss2(_data);

        //Set up maze
        getMaze(LEVEL4_MAZE_FILEPATH);
        cout<<"Level4.h: "<<endl;

        IntRect rtrap(0,0,32,39);

        //Draw the map out according to their position in maze txt file
        for(int i=0;i<20;i++)
        {
            for (int j=0;j<20;j++)
            {
                if(maze[i][j]=='w')
                {
                    smaze[i][j].setTexture(_data->assets.GetTexture("Wall"));
                    smaze[i][j].setScale(0.18f,0.18f);
                    smaze[i][j].setPosition(j*40, i*30);

                }
                else
                {
                    smaze[i][j].setTexture(_data->assets.GetTexture("Floor"));
                    smaze[i][j].setScale(0.33f,0.33f);
                    smaze[i][j].setPosition(j*40, i*30);

                        if(maze[i][j]=='n') //player
                        {
                            maze[i][j]='f';
                            roulant->posY=i;
                            roulant->posX=j;
                            roulant->roulant.setPosition(j*40,i*27);
                            roulant->roulant.setScale(0.9f,0.9f);
                        }
                        else if(maze[i][j]=='e')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elf->posY=i;
                                elf->posX=j;
                                elf->elf.setPosition(j*40,i*30);
                                elf->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='m')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfm->posY=i;
                                elfm->posX=j;
                                elfm->elf.setPosition(j*40,i*30);
                                elfm->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='y')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfy->posY=i;
                                elfy->posX=j;
                                elfy->elf.setPosition(j*40,i*30);
                                elfy->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='l')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfl->posY=i;
                                elfl->posX=j;
                                elfl->elf.setPosition(j*40,i*30);
                                elfl->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='v')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfv->posY=i;
                                elfv->posX=j;
                                elfv->elf.setPosition(j*40,i*30);
                                elfv->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='a')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfa->posY=i;
                                elfa->posX=j;
                                elfa->elf.setPosition(j*40,i*30);
                                elfa->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='p')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfp->posY=i;
                                elfp->posX=j;
                                elfp->elf.setPosition(j*40,i*30);
                                elfp->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='o')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfo->posY=i;
                                elfo->posX=j;
                                elfo->elf.setPosition(j*40,i*30);
                                elfo->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='j')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfj->posY=i;
                                elfj->posX=j;
                                elfj->elf.setPosition(j*40,i*30);
                                elfj->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='u')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfu->posY=i;
                                elfu->posX=j;
                                elfu->elf.setPosition(j*40,i*30);
                                elfu->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='i')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elfi->posY=i;
                                elfi->posX=j;
                                elfi->elf.setPosition(j*40,i*30);
                                elfi->elf.setScale(1.0f,1.0f);
                            }
                        }

                        else if(maze[i][j]=='t')
                        {
                            smaze[i][j].setTexture(_data->assets.GetTexture("Trap"));
                            smaze[i][j].setTextureRect(rtrap);
                            smaze[i][j].setScale(0.8f,0.8f);
                            smaze[i][j].setPosition(j*40, i*30);
                        }
                        else if(maze[i][j]=='s')
                        {
                            smaze[i][j].setTexture(_data->assets.GetTexture("Statue"));
                            smaze[i][j].setScale(0.13f,0.13f);
                            smaze[i][j].setPosition(j*40, i*30);
                        }
                        else if(maze[i][j]=='b')
                        {
                            maze[i][j]='f';
                            boss2->posY=i;
                            boss2->posX=j;
                            boss2->boss.setPosition(j*40,i*28);
                            boss2->boss.setScale(0.8f,0.8f);
                        }
                    }
                }
            }
            cout<<"map loaded\n";
    }

    void Level4::Update(float deltaTime)
    {
        ofstream writeFile("Assets/PlayerData/HighestScoreLevel4.txt");
        if(writeFile.is_open())
        {
            if(scr>highestScr)
            {
                highestScr=scr;
            }
            writeFile << highestScr;
        }
        writeFile.close();
        if(elf->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elf->elfDie=true;
                maze[elf->posY][elf->posX]='f';
                elf->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfm->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfm->elfDie=true;
                maze[elfm->posY][elfm->posX]='f';
                elfm->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfy->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfy->elfDie=true;
                maze[elfy->posY][elfy->posX]='f';
                elfy->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfl->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfl->elfDie=true;
                maze[elfl->posY][elfl->posX]='f';
                elfl->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfv->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfv->elfDie=true;
                maze[elfv->posY][elfv->posX]='f';
                elfv->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfa->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfa->elfDie=true;
                maze[elfa->posY][elfa->posX]='f';
                elfa->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfp->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfp->elfDie=true;
                maze[elfp->posY][elfp->posX]='f';
                elfp->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfo->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfo->elfDie=true;
                maze[elfo->posY][elfo->posX]='f';
                elfo->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfj->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfj->elfDie=true;
                maze[elfj->posY][elfj->posX]='f';
                elfj->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfu->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfu->elfDie=true;
                maze[elfu->posY][elfu->posX]='f';
                elfu->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elfi->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elfi->elfDie=true;
                maze[elfi->posY][elfi->posX]='f';
                elfi->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(boss2->boss.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                boss2->bossDie=true;
                maze[boss2->posY][boss2->posX]='f';
                boss2->boss.setScale(0,0);
                scr+=500;
                cout<<"boss Die\n";
            }
            roulant->isAttack=false;
        }

        if(maze[roulant->posY][roulant->posX] == 'k' )
        {
            lvlComplete=true;
            cout<<"win";
        }

        timerev += dt;
        if (timerev > 1.0f)
        {
            //deduct live when player touch elf
            if(elf->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfm->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfy->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfl->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfv->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfa->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfp->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfo->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfj->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfu->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elfi->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
            {
                if(roulant->lives>0)
                {
                    cout<<"l:"<<roulant->lives;
                    roulant->lives--;
                    scr-=10;
                }
            }
            if(boss2->boss.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
            {
                boss2->bossAttack=true;
                if(roulant->lives>0)
                {
                    cout<<"l:"<<roulant->lives;
                    roulant->lives--;
                    scr-=10;
                }
                 boss2->bossAttack=false;
            }
            //plus live when player touch statue
            if(maze[roulant->posY][roulant->posX] == 's'&& roulant->lives<3)
            {
                maze[roulant->posY][roulant->posX]= 'f';
                roulant->lives +=1;
                cout<<"l:"<<roulant->lives;

            }
                //touch exit tile to complete level

                //deduct live when player touch trap
            if(maze[roulant->posY][roulant->posX] == 't' )
            {
                if(roulant->lives>0)
                {
                    cout<<"trap";
                    roulant->lives--;
                    scr-=10;
                }
            }
                //deduct live when touch boss
            if(maze[roulant->posY][roulant->posX]=='b')
            {
                roulant->lives-=1;
                scr-=10;
            }
            if(maze[roulant->posY][roulant->posX]=='c')
            {
                roulant->lives-=1;
                scr-=100;
            }
            timerev=0;
        }
        timere+=dt;
        if(timere>0.5f)
        {
            int elfMove1 = rand ()%4 ;
            int elfMove2 = rand()%4 ;
            int elfMove3 = rand ()%4 ;
            int elfMove4 = rand()%4 ;
            int elfMove5 = rand ()%4 ;
            int elfMove6 = rand()%4 ;
            elf->randomMove(elfMove1,maze);
            elfm->randomMove(elfMove2,maze);
            elfy->randomMove(elfMove3,maze);
            elfl->randomMove(elfMove4,maze);
            elfv->randomMove(elfMove5,maze);
            elfa->randomMove(elfMove6,maze);
            elfp->randomMove(elfMove4,maze);
            elfo->randomMove(elfMove1,maze);
            elfj->randomMove(elfMove6,maze);
            elfu->randomMove(elfMove2,maze);
            elfi->randomMove(elfMove5,maze);
            boss2->randomMove(elfMove3,maze);
            timere=0;
        }
        if(lvlComplete)
        {
            if(scr>=300)
            {
                cout<<"Level4 complete\n";
                this->_data->stateManager.AddState(StateRef (new EndScreen3(this->_data,this->scr,this->highestScr)));
                lvlComplete=false;
            }
            else
                lvlComplete=false;

        }
        if(roulant->lives == 0 )
        {
            cout<<"Lose";
            this->_data->stateManager.AddState(StateRef (new GameOver3(_data)));


        }
        roulant->UpdateAnimation();
        elf->UpdateElfAni();
        elfm->UpdateElfAni();
        elfy->UpdateElfAni();
        elfl->UpdateElfAni();
        elfv->UpdateElfAni();
        elfa->UpdateElfAni();
        elfp->UpdateElfAni();
        elfo->UpdateElfAni();
        elfj->UpdateElfAni();
        elfu->UpdateElfAni();
        elfi->UpdateElfAni();
        boss2->UpdateBossAni();

    }

    void Level4::HandleInput()
    {
        //Set up texts for hud and other interface
        live.setFont(font);
        score.setFont(font);
        highestScore.setFont(font);

        //live count
        live.setCharacterSize(20);
        live.setPosition(_data->window.getSize().x/4-50.f,10);
        live.setFillColor(Color::White);

        //score
        score.setCharacterSize(20);
        score.setPosition(_data->window.getSize().x/2,10);
        score.setFillColor(Color::White);

        //display highest score
        highestScore.setCharacterSize(20);
        highestScore.setPosition(_data->window.getSize().x/2+200.f,10);
        highestScore.setFillColor(Color::White);

        live.setString("Live : " + to_string(roulant->lives));
        score.setString("Score : " + to_string(scr));
        highestScore.setString("Highest score : "+ to_string(highestScr));

        Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                this->_data->window.close();
            }

            else if(event.type ==Event::KeyPressed)
            {
                timer+=dt;
                if(timer>0.01f)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Key::S))
                    {
                        roulant->moving('D',maze);
                    }
                    if(Keyboard::isKeyPressed(Keyboard::Key::W))
                    {
                        roulant->moving('U',maze);
                    }
                    if(Keyboard::isKeyPressed(Keyboard::Key::A))
                    {
                        roulant->moving('L',maze);
                    }
                    if(Keyboard::isKeyPressed(Keyboard::Key::D))
                    {
                        roulant->moving('R',maze);
                    }
                    if(elf->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfm->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfy->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfl->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfv->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfa->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfp->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfo->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfj->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfu->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                        ||elfi->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                       || boss2->boss.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
                    {
                        if(Keyboard::isKeyPressed(Keyboard::Key::Space))
                        {
                            roulant->moving('A',maze);
                            roulant->isAttack=true;
                        }
                    }
                    timer=0;
                }
            }
        }
    }


    void Level4::Draw(float deltaTime)
    {
        this->_data->window.clear();
               //display things out

        for (int i=0; i<20; i++)
        {
            for (int j=0; j<20; j++)
            {
                this->_data->window.draw(smaze[i][j]);
            }
        }

            this->_data->window.draw(live);
            this->_data->window.draw(score);
            this->_data->window.draw(highestScore);
            roulant->Draw();
            elf->Draw();
            elfm->Draw();
            elfy->Draw();
            elfl->Draw();
            elfv->Draw();
            elfa->Draw();
            elfp->Draw();
            elfo->Draw();
            elfj->Draw();
            elfu->Draw();
            elfi->Draw();
            boss2->Draw();
            this->_data->window.display();

    }
}











