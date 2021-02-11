#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <thread>
#include <vector>
#include "utils.h"
using namespace std;

#define upperLimit 0
#define leftLimit 0

int row = 25;
int col = 100;
bool found_exit = false;
vector<vector<char>> maze_map;


int main()
{

    int in_x,in_y;

    if(!get_maze(&in_x,&in_y,row,col)){
        return 0;
    }
    // Thread que imprime o labirinto(maze_map)
    std::thread updateScreen(output);
    updateScreen.detach();
    // Thread para caminhar pelo labirinto(maze_map)
    std::thread walk(maze_actions,in_x,in_y);
    walk.detach();
    // Enquanto a saida do labirinto não for encontrada, o programa não termina.
	while(!found_exit);
	// Aguarda antes de encerrar
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
	
	return 0;
}


// void threading_map(bool* cur_thread, int* nextY, int* nextX, vector<vector<char>> maze_map, int newWayY, int newWayX){
    
//     // Search available path
//     if(maze_map[newWayY][newWayX] == ' ' || maze_map[newWayY][newWayX] == 'O'){ //cambio
//         if(!cur_thread){
//             // The current thread moves one step forward/left/right without creating a new thread
//             *cur_thread = true;
//             *nextY = newWayY;
//             *nextX = newWayX;
//         }else{
//             //Crea un nuevo hilo en la nueva dirección
//             std::thread newthreading_map(maze_actions,newWayY,newWayX);
//             newthreading_map.detach();
//         }
//     }    
// }

