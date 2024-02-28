NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

HEADER = -I ./includes -I $(LIBFT)

LIBS = $(LIBFT)/libft.a

SOURCES = src/main.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBS)
	@$(CC) $(CFLAGS) $(HEADER) $(OBJECTS) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft