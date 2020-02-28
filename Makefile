NAME = fractol

FILES = main.c fractal.c fractal_op.c events.c

OFILES = main.o fractal.o fractal_op.o events.o

CFLAGS = -Wextra -Werror -Wall

CC = gcc

all: $(NAME)

$(NAME): $(OFILES)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) -lmlx -framework OpenGL -framework Appkit libft/libft.a $(OFILES)

clean:
	@make fclean -C libft
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re:	fclean all