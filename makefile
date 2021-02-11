all: main

main: main.cpp load.cpp output.cpp maze_actions.cpp threading_map.cpp
	g++ -pthread -lstdc++ main.cpp load.cpp output.cpp maze_actions.cpp threading_map.cpp -o main