NAME = philo

SRC = src/main.c \
		src/errors.c \
		src/utils.c \


OBJ = $(SRC:.c=.o)


INCLUDE = include

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)





src/%.o: src/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(LIBFT) $(PRINTF)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
