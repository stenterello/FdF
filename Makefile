NAME=FdF
FLAGS=-Wall -Werror -Wextra -g
LIBFT=./libft/libft.a
SRCFLS= main.c \
		read_map.c \
		read_map_utils.c \
		win.c \
		draw.c \
		draw_utils.c \
		events.c

SRC = $(addprefix src/, $(SRCFLS))
OBJS=$(SRC:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I/usr/include -Imlx_linux -O0 -c $< -o $@

lin: $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT) ./mlx_linux/libmlx.a -Lmlx_linux -L/usr/lib -L/usr/include -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ../libft 

clean:
	rm -f *.o
	$(MAKE) clean -C ../libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ../libft
