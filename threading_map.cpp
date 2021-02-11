#include <iostream>
#include <thread>
#include <vector>
#include "utils.h"
using namespace std;


void threading_map(bool* cur_thread, int* nextY, int* nextX, vector<vector<char>> maze_map, int newWayY, int newWayX){
    
    // Search available path
    if(maze_map[newWayY][newWayX] == ' ' || maze_map[newWayY][newWayX] == 'O'){ //cambio
        if(!cur_thread){
            // The current thread moves one step forward/left/right without creating a new thread
            *cur_thread = true;
            *nextY = newWayY;
            *nextX = newWayX;
        }else{
            //Create new thread in new direction
            thread newthreading_map(maze_actions,newWayY,newWayX);
            newthreading_map.detach();
        }
    }    
}

