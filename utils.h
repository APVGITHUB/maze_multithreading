#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void maze_actions(int y, int x);
void output();
int get_maze(int* in_x, int* in_y,int row,int col);
void threading_map(bool* cur_thread, int* next_y, int* next_x, vector<vector<char>> maze_map, int new_y, int new_x);