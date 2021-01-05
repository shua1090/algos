build:
	g++ $(wildcard Structures/*.cpp) -o bin/main.exe

run:build
	./bin/main.exe