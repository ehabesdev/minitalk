

NAME = server client

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

server: server.c $(LIBFT)
	gcc server.c -L$(LIBFT_DIR) -lft -o server

client: client.c $(LIBFT)
	gcc client.c -L$(LIBFT_DIR) -lft -o client

clean:
	make -C $(LIBFT_DIR) clean
	rm -f *.o

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


