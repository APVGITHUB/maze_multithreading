#include <iostream>
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
    
    thread show_output(output);
    show_output.detach();
   
    thread maze_planning(maze_actions,in_x,in_y);
    maze_planning.detach();

	while(!found_exit);
	
	return 0;
}


