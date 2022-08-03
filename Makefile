CC=gcc
SOURCE=./src
FLAGS=-Wall -Wextra -O0 -fsanitize=address
DEBUG=-g
OBJ=-c
BIN=./bin



all:
	make main

DFA_builder: $(SOURCE)/DFA_builder.c
	$(CC) $(FLAGS) $(DEBUG) $(OBJ) $(SOURCE)/DFA_builder.c -o $(BIN)/DFA_builder

RE_parser: $(SOURCES)/RE_parser.c 
	$(CC) $(FLAGS) $(DEBUG) $(OBJ) $(SOURCE)/RE_parser.c -o $(BIN)/RE_parser.o

main: RE_parser DFA_builder $(SOURCE)/main.c
	$(CC) $(FLAGS) $(DEBUG) $(SOURCE)/main.c $(BIN)/RE_parser.o $(BIN)/RE_parser.o -o $(BIN)/main

clean :
	rm -f RE_parser RE_parse_tree.txt
