NAME = push_swap
LIBFT_PATH = library/libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I ./includes -I $(LIBFT_PATH)
CFLAGS = -g -Wall -Wextra -Werror $(includes)

SRCS = moves.c moves2.c order.c main.c utils.c utilsextension.c validatestack.c
OBJS = $(addprefix sources/,$(SRCS:%.c=%.o))

RM = rm -f

all: libft $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		cc $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $@

clean:
	@rm	-f $(OBJS)
	@make $@ -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make $@ -C $(LIBFT_PATH)

re: fclean all
	@make $@ -C $(LIBFT_PATH)

libft:
	make -C $(LIBFT_PATH)