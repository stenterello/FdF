NAME=FdF
FLAGS=-Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)