NAME = so_long

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -I/usr/include/minilibx-linux

RM = rm -f

SRC = 	so_long.c\
		read_map.c\
		libft.c\
		check_map.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		so.c\
		movement.c\
		keyhook.c\
		healper.c

OBJ	=$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY: clean
