#include <iostream>
#include <thread>
#include <vector>
#include "utils.h"
using namespace std;


void threading_map(bool* cur_thread, int* next_y, int* next_x, vector<vector<char>> maze_map, int new_y, int new_x){
    
    // Search available path
    if(maze_map[new_y][new_x] == ' ' || maze_map[new_y][new_x] == 'O'){
        if(!cur_thread){
            // The current thread moves one step forward/left/right without creating a new thread
            *cur_thread = true;
            *next_y = new_y;
            *next_x = new_x;
        }else{
            //Create new thread in new direction
            thread newthreading_map(maze_actions,new_y,new_x);
            newthreading_map.detach();
        }
    }    
}

