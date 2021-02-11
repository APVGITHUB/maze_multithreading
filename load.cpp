#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

extern vector<vector<char>> maze_map;

int get_maze(int* in_x, int* in_y,int row,int col){

    ifstream file;
    int i,j;

    file.open("labyrinth.txt");
    if(!file.good()){
        cout << "Error when opening file";
        return 0;
    }

    // Asigna una matriz con la dimensión leída del archivo
    maze_map.resize(row);
    for (i = 0; i < row; i++){
        maze_map[i].resize(col);
    }
    
    
    // Copia la matriz del archivo a la matriz asignada
    string t;
    for(i=0; i < row; i++){
        getline(file,t);
        for(j=0; j< col; j++){
            maze_map[i][j]=t[j];
            if(maze_map[i][j] == 'I'){
                *in_x = i;
                *in_y = j;
            }
        }
    }

    file.close();
}
