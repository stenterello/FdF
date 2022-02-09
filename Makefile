NAME=FdF
FLAGS=-Wall -Werror -Wextra -g

$(NAME):
	gcc $(FLAGS) -I /usr/local/include main.c libft/libft.a get_next_line/*.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)