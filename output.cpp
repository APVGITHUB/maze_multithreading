#include <iostream>
#include <vector>

using namespace std;

extern vector<vector<char>> maze_map;
extern bool found_exit;
extern int row,col;

void output(){

    int i,j;
    while(!found_exit){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
        for(i=0; i < row; i++){
            for(j=0; j< col; j++){
                std::cout << maze_map[i][j];
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }
}