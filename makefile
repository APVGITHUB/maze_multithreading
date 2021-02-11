all: main

main: main.cpp load.cpp output.cpp maze_actions.cpp
	g++ -pthread -lstdc++ main.cpp load.cpp output.cpp maze_actions.cpp -o main