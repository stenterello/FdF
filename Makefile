NAME=FdF
FLAGS=-Wall -Werror -Wextra -g
LIBFT=./libft/libft.a
SRCFLS= main.c \
		read_map.c \
		read_map_utils.c \
		win.c \
		draw.c \
		draw_utils.c

SRC = $(addprefix src/, $(SRCFLS))
OBJS=$(SRC:.c=.o)

$(NAME): $(LIBFT)
	gcc $(FLAGS) -I /usr/local/include main.c init_map.c init_map_utils.c $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I/usr/include -Imlx_linux -O0 -c $< -o $@

lin: $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT) ./mlx_linux/libmlx.a -Lmlx_linux -L/usr/lib -L/usr/include -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


# -lmlx_Linux

$(LIBFT):
	$(MAKE) bonus -C ../libft 

clean:
	rm -f *.o
	$(MAKE) clean -C ../libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ../libft
