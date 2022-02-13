NAME=FdF
FLAGS=-Wall -Werror -Wextra -g
LIBFT=./libft/libft.a
SRC= main.c \
		init_map.c \
		init_map_utils.c \
		draw_utils.c \
		utils.c

OBJS=$(SRC:.c=.o)

$(NAME): $(LIBFT)
	gcc $(FLAGS) -I /usr/local/include main.c init_map.c init_map_utils.c $(LIBFT) get_next_line/*.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

lin: $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT) get_next_line/*.c mlx_linux/libmlx.a -Lmlx_linux -L/usr/lib -L/usr/include -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


# -lmlx_Linux

$(LIBFT):
	$(MAKE) bonus -C ./libft 

clean:
	rm -f *.o
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

