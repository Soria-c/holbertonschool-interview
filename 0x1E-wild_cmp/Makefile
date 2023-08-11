CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g3 -I./
HEADER = holberton.h
BETTY = betty

SRC0 = test/0-main.c 0-wildcmp.c
OBJ0 = $(patsubst %.c, obj/%.o, $(SRC0))
NAME0 = bin/0-wildcmp

.PHONY: directories all clean fclean re task0

all: directories task0

directories:
	mkdir -p obj bin obj/test

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

task0: directories $(HEADER) $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0) $(LIB)
	./$(NAME0)

clean:
	$(foreach var, $(ALLNAME), $(RM) *~ $(var))
	$(RM) save.hblk

oclean:
	$(foreach var, $(ALLOBJ), $(RM) $(var))

fclean: clean oclean

re: oclean all

betty:
	$(BETTY) *.c **/**.c *.h Makefile
