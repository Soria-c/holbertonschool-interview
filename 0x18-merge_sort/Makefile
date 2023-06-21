CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror=vla -pedantic
CFILES = 0-main.c 0-merge_sort.c print_array.c -o
NAME = merge

all: compile run clean

gdb: compile rungdb clean


compile:
	$(CC) $(CFLAGS) $(CFILES) $(NAME)

run:
	./$(NAME)

rungdb:
	gdb ./$(NAME)

clean:
	rm $(NAME)

betty:
	betty *.c *.h
