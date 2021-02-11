all: main

main: main.cpp load.cpp output.cpp
	g++ -pthread -lstdc++ main.cpp load.cpp output.cpp -o main