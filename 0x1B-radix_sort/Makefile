CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
BETTY = betty
HEADER = sort.h

SRC0 = 0-main.c 0-radix_sort.c print_array.c
OBJ0 = $(patsubst %.c, obj/%.o, $(SRC0))
NAME0 = bin/radix

directory:
	mkdir -p bin obj

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

task0: directory $(HEADER) $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)
	./$(NAME0)

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(foreach var, $(OBJ0), $(RM) $(var))

fclean: clean oclean

re: oclean all

betty:
	$(BETTY) *.c *.h Makefile
