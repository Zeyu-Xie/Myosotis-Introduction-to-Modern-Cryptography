.PHONY: ALL main test clean clean_win

ALL: main

main: Bint.cpp main.cpp func.cpp func.hpp Bint.hpp
	g++ Bint.cpp main.cpp func.cpp -o main --std=c++11

test: Bint.cpp test.cpp func.cpp func.hpp Bint.hpp
	g++ Bint.cpp test.cpp func.cpp -o test --std=c++11

clean:
	rm -f main main.exe test test.exe

# clean command for windows powershell
clean_win:
	del main main.exe test test.exe