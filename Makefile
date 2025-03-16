NAME = so_long

CC = cc

CFLAGS = -Werror -Wall -Wextra -I/mnt/c/Users/User/OneDrive/Desktop/so_long/minilibx-linux

RM = rm -f

SRC = 	so_long.c\
		read_map.c\
		libft.c\
		check_map.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		so.c\
		movement.c

OBJ	=	$(SRC:.c = .o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -L/mnt/c/Users/User/OneDrive/Desktop/so_long/minilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean :
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re : clean all
.PHONY: all clean re fclean