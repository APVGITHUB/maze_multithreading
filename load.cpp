#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <thread>
#include <vector>

using namespace std;

// extern int row = 25;
// extern int col = 100;

extern vector<vector<char>> maze_map;


int get_maze(int* in_x, int* in_y,int row,int col){
    // Preenche a matriz lendo o arquivo de entrada

    ifstream file;
    int i,j;

    // Abre o arquivo 'maze.txt'
    file.open("labyrinth.txt");
    if(!file.good()){
        // Arquivo não foi aberto corretamente
        std::cout << "Error when opening file";
        return 0;
    }

    //Aqui indica las dimensiones NxM del maze, escritas 
    //en la primera fila del txt. Buscar otra forma de hacerlo sin poner fila extra 
    // file >> row >> col; 
 

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
            // cout<<"EL VALor T"+t<<endl;
            // cout<<i<<endl;
            // cout<<j<<endl;
            maze_map[i][j]=t[j];
            if(maze_map[i][j] == 'I'){
                *in_x = i;
                *in_y = j;
            }
        }
        cout<<endl;
    }

    file.close();
    return 1;
}
