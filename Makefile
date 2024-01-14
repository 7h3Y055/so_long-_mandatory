NAME = so_long
SRCS = so_long.c  utilis0.c  utilis1.c  utilis2.c  utilis3.c  utilis4.c
CFLAGS = -Wall -Werror -Wextra -L/usr/lib -lXext -lX11 
LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a

all:$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx-linux

$(NAME): $(LIBFT) $(MLX)
	gcc $(SRCS) $(MLX) $(LIBFT) $(CFLAGS) -o $(NAME)

clean:
	make clean -C ./libft
fclean:
	make fclean -C ./libft
	make clean -C ./minilibx-linux
	rm -f $(NAME)

re:fclean all

