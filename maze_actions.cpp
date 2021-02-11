#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <thread>
#include <vector>
#include "utils.h"
using namespace std;

extern vector<vector<char>> maze_map;
extern bool found_exit;
extern int row,col;

void maze_actions(int y, int x){
    
    /* El laberinto se representa en el cuarto cuadrante del palno cartesiano, así
    las columnas son la x del plano y las rectas son la y*/

    // found exit
	if(maze_map[y][x] == 'O'){
        found_exit = true;
    }

	maze_map[y][x] =  'o';

	std::this_thread::sleep_for(std::chrono::milliseconds(200));

    // Variaveis para fazer com que a thread atual continue em seu caminho
	bool cur_thread = false;
    int nextY, nextX;

    // Prueba las posibles rutas
    if(y > 0){
        // Para cima
        wayAhead(&cur_thread, &nextY, &nextX, maze_map, y-1, x);
    }
	if((y+1) < row){
        // Para baixo
        wayAhead(&cur_thread, &nextY, &nextX, maze_map, y+1, x);
    }
    if(x > 0){
        // Para a esquerda
        wayAhead(&cur_thread, &nextY, &nextX, maze_map, y, x-1);
    }
	if((x+1) < col){
	    // Para direita
        wayAhead(&cur_thread, &nextY, &nextX, maze_map, y, x+1);
    }
    if(cur_thread){
        // Continua no mesmo caminho, sem criar uma nova thread.
        maze_actions(nextY,nextX);
    }
    // Path drawing
	maze_map[y][x] = '+'; 
}