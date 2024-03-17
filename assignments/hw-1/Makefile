.PHONY: ALL clean

ALL: main

main: Bint.cpp main.cpp
	g++ Bint.cpp main.cpp -o main --std=c++11

clean:
	rm -f main main.exe

clean_win:
	del main.exe