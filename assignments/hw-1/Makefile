.PHONY: ALL clean

ALL: main

main: Bint.cpp main.cpp
	g++ Bint.cpp main.cpp func.cpp -o main --std=c++11

test: Bint.cpp test.cpp
	g++ Bint.cpp test.cpp func.cpp -o test --std=c++11

clean:
	rm -f main main.exe test test.exe

# clean command for windows powershell
clean_win:
	del main main.exe test test.exe