C = gcc
C_FLAGS = -Wextra -Wall -pedantic
SRC = src/*

all:
	$(C) $(C_FLAGS) -Iinclude $(SRC) -o out
