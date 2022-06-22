#include "GameMec.h"
#include "GameOver.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Maze.h"
#include "EndScreen.h"
#include "GameManager.h"
#include "Definition.h"
#include "Roulant.h"
#include "Elf.h"



using namespace std;
using namespace sf;

namespace Engine
{
    GameMec::GameMec(GameDataRef data): _data(data)
    {
        scr=0;
    }

    void GameMec::Init()
    {
        ifstream readFile;
        readFile.open("Assets/PlayerData/HighestScoreLevel1.txt");
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
        font.loadFromFile(FONT_FILEPATH);
        cout <<"Font Loaded\n";
        cout << "Complete Loading\n";

        roulant = new Roulant(_data);
        elf = new Elf(_data);
        elf1 = new Elf(_data);
        elf2 = new Elf(_data);
        elf3 = new Elf(_data);

        //Set up maze
        getMaze(LEVEL1_MAZE_FILEPATH);
        cout<<"GameMec.h: "<<endl;

        IntRect rtrap(0,0,32,39);

        //Draw the map out according to their position in maze txt file
        for(int i=0;i<20;i++)
        {
            for (int j=0;j<20;j++)
            {
                if(maze[i][j]=='w')
                {
                    smaze[i][j].setTexture(_data->assets.GetTexture("Wall"));
                    smaze[i][j].setScale(0.19f,0.20f);
                    smaze[i][j].setPosition(j*40, i*30);
                }
                else
                {
                    smaze[i][j].setTexture(_data->assets.GetTexture("Floor"));
                    smaze[i][j].setScale(0.34f,0.34f);
                    smaze[i][j].setPosition(j*40, i*30);

                        if(maze[i][j]=='n') //player
                        {
                            maze[i][j]='f';
                            roulant->posY=i;
                            roulant->posX=j;
                            roulant->roulant.setPosition(j*35,i*25);
                            roulant->roulant.setScale(1.0f,1.0f);
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
                        else if(maze[i][j]=='a')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elf1->posY=i;
                                elf1->posX=j;
                                elf1->elf.setPosition(j*40,i*30);
                                elf1->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='i')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elf2->posY=i;
                                elf2->posX=j;
                                elf2->elf.setPosition(j*40,i*30);
                                elf2->elf.setScale(1.0f,1.0f);
                            }
                        }
                        else if(maze[i][j]=='o')
                        {
                            if(elfDie==false)
                            {
                                maze[i][j]='f';
                                elf3->posY=i;
                                elf3->posX=j;
                                elf3->elf.setPosition(j*40,i*30);
                                elf3->elf.setScale(1.0f,1.0f);
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
                            smaze[i][j].setPosition(j*40.5, i*30);
                        }
                    }
                }
            }
            cout<<"map loaded\n";
    }

    void GameMec::Update(float deltaTime)
    {
        ofstream writeFile("Assets/PlayerData/HighestScoreLevel1.txt");
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
        if(elf1->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elf1->elfDie=true;
                maze[elf1->posY][elf1->posX]='f';
                elf1->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elf2->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elf2->elfDie=true;
                maze[elf2->posY][elf2->posX]='f';
                elf2->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
            }
            roulant->isAttack=false;
        }
        if(elf3->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
        {
            if(roulant->isAttack == true)
            {
                elf3->elfDie=true;
                maze[elf3->posY][elf3->posX]='f';
                elf3->elf.setScale(0,0);
                scr+=200;
                cout<<"elf Die\n";
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
               || elf1->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               || elf2->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
               ||elf3->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
            {
                roulant->playerOuch=true;
                if(roulant->lives>0)
                {
                    cout<<"l:"<<roulant->lives;
                    scr-=10;
                    roulant->lives--;
                }
            }
            //plus live when player touch statue
            if(maze[roulant->posY][roulant->posX] == 's'&& roulant->lives<3)
            {
                maze[roulant->posY][roulant->posX]= 'f';
                roulant->lives +=1;
                cout<<"l:"<<roulant->lives;

            }
            //deduct live when player touch trap
            if(maze[roulant->posY][roulant->posX] == 't' )
            {
                roulant->playerOuch=true;
                if(roulant->lives>0)
                {
                    cout<<"trap";
                    scr-=10;
                    roulant->lives--;
                }
            }
            timerev=0;
        }
        //set elf random move
        timere+=dt;
        if(timere>0.5f)
        {
            int elfMove1 = rand ()%4 ;
            int elfMove2 = rand ()%4 ;
            int elfMove3 = rand ()%4 ;
            int elfMove4 = rand ()%4 ;
            elf->randomMove(elfMove1,maze);
            elf1->randomMove(elfMove2,maze);
            elf2->randomMove(elfMove3,maze);
            elf3->randomMove(elfMove4,maze);
            timere=0;
        }
        if(lvlComplete)
        {
            if(scr>=150)
            {
                cout<<"Level1 complete\n";
                this->_data->stateManager.AddState(StateRef (new EndScreen(this->_data,this->scr,this->highestScr)));
                lvlComplete=false;
            }
            else
                lvlComplete=false;
        }
        if(roulant->lives == 0 )
        {
            cout<<"Lose";
            this->_data->stateManager.AddState(StateRef (new GameOver(_data)));
        }
        roulant->UpdateAnimation();
        elf->UpdateElfAni();
        elf1->UpdateElfAni();
        elf2->UpdateElfAni();
        elf3->UpdateElfAni();
    }

    void GameMec::HandleInput()
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
                       ||elf1->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                       ||elf2->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds())
                       ||elf3->elf.getGlobalBounds().intersects(roulant->roulant.getGlobalBounds()))
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




    void GameMec::Draw(float deltaTime)
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
            elf1->Draw();
            elf2->Draw();
            elf3->Draw();
            this->_data->window.display();

    }
}











