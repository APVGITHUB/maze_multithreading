#include <iostream>
#include <thread>
#include <vector>

using namespace std;

extern vector<vector<char>> maze_map;
extern bool found_exit;
extern int row,col;

void output(){

    int i,j;
    while(!found_exit){
        for(i=0; i < row; i++){
            for(j=0; j< col; j++){
                cout << maze_map[i][j];
            }
            cout << "\n";
        }
        cout << "\n\n";
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}