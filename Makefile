.PHONY: all clean fclean re

NAME = philo

FLAGS = -Wall -Wextra -Werror -Iinclude

LIBFT_ARCHIVE = include/LIBFT/libft.a

SOURCES = src/main.c \
	src/check_args.c \

OBJECTS = $(SOURCES:src/.c=obj/.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_ARCHIVE)
	cc $(FLAGS) $(LIBFT_ARCHIVE) $(OBJECTS) -o $(NAME)

obj/.o: src/.c
	mkdir -p obj
	cc $(FLAGS) -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C include/LIBFT

clean:
	rm -rf obj
	$(MAKE) fclean -s -C include/LIBFT

fclean:
	rm -f $(NAME)
	$(MAKE) fclean -s -C include/LIBFT

re: fclean all
