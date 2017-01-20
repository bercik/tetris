CXX      = g++
LIBS     = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS  += -pedantic -Wall -O0 -g -std=c++11
NAME     = tetris

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: program

.cpp.o:
	$(CXX) $(CFLAGS) -c -o $@ $<

program: $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

peace:
	clear && make clean && make | head -n 20 && echo "-----" && ./$(NAME) && echo "-----" && valgrind ./$(NAME) 2>&1 | tail -n 10

clean:
	rm -f $(OBJ) $(NAME)
	rm -f *.o

run: program
	./$(NAME)

.PHONY: all program peace clean run
