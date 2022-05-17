
output: main.o stats.o player.o monster.o
	clang++ main.o stats.o player.o monster.o -o output

main.o: main.cpp
	clang++ -c main.cpp

stats.o: stats.cpp stats.h
	clang++ -c stats.cpp

player.o: player.cpp player.h
	clang++ -c player.cpp

monster.o: monster.cpp monster.h
	clang++ -c monster.cpp

target: dependencies
	action
