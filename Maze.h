#pragma once
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>


//to read the maze level file

using namespace sf;
using namespace std;

namespace Engine
{
    class Maze
    {
        private:

        public:

             char maze[20][20];
            Maze(){}
            ~Maze(){}

            bool getMaze(string filename)
            {

                ifstream mazeFile;
                mazeFile.open(filename);
                cout<<filename;
                cout<<endl;
                for (int i =0; i<20; i++)
                {
                    for (int j=0; j<20; j++)
                    {
                        mazeFile>> maze[i][j];
                        cout<<maze[i][j];
                    }
                    cout<<endl;
                }
                mazeFile.close();
                return true;
            }
    };

}

