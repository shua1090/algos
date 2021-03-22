run:build
	./bin/main.exe
build:
	# g++ $(wildcard Structures/*.cpp) -o bin/main.exe
	g++ -Iinclude Structures/selectedSort.cpp -o bin/main.exe 
