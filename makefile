all: build
build: main.cpp
	g++ -o build main.cpp -lraylib

