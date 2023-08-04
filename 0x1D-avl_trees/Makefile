CC = gcc
# Special flag for GCC -no-pie which allows a non PIE executable.
# -L./include -lavl
CFLAGS = -no-pie -Wall -Wextra -Werror -pedantic -g3
LIB = include/libavl.a
HEADER = binary_trees.h
BETTY = betty

SRC0 = binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c
OBJ0 = $(patsubst %.c, obj/%.o, $(SRC0))
NAME0 = bin/0-is_avl

.PHONY: all directories clean oclean fclean re betty task0

all: directories task0

directories:
	mkdir -p obj bin

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

task0: directories $(HEADER) $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0) $(LIB)
	./$(NAME0)

clean:
	$(RM) $(NAME0)

oclean:
	$(RM) $(OBJ0)

fclean: clean oclean

re: oclean all

betty:
	$(BETTY) *.c *.h Makefile
