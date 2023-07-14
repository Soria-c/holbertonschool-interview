CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
BETTY = betty

SRC0 = 0-main.c 0-add_node.c
OBJ0 = $(patsubst %.c, obj/%.o, $(SRC0))
NAME0 = bin/add_node

.PHONY: all

directories:
	mkdir -p obj bin

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: directories $(OBJ0) compile run

compile:
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

run:
	./$(NAME0)

clean:
	$(RM) *~ $(NAME0) bin/$(NAME0)

oclean:
	$(RM) *~ $(OBJ0)

fclean: clean oclean

re: oclean all

betty:
	$(BETTY) *.c *.h Makefile
