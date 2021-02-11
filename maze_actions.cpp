#include <iostream>
#include <thread>
#include <vector>
#include "utils.h"
using namespace std;

extern vector<vector<char>> maze_map;
extern bool found_exit;
extern int row,col;

void maze_actions(int y, int x){
    
    // found exit
	if(maze_map[y][x] == 'O'){
        found_exit = true;
    }

	maze_map[y][x] = 'o';

	this_thread::sleep_for(chrono::milliseconds(200));

	bool cur_thread = false;
    int next_y, next_x;

    // Test actions
    if(y > 0){
        threading_map(&cur_thread, &next_y, &next_x, maze_map, y-1, x);
    }
	if((y+1) < row){
        threading_map(&cur_thread, &next_y, &next_x, maze_map, y+1, x);
    }
    if(x > 0){
        threading_map(&cur_thread, &next_y, &next_x, maze_map, y, x-1);
    }
	if((x+1) < col){
        threading_map(&cur_thread, &next_y, &next_x, maze_map, y, x+1);
    }
    if(cur_thread){
        maze_actions(next_y,next_x);
    }
    // Path drawing
	maze_map[y][x] = '+'; 
}