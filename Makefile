NAME = push_swap
LIBFT_PATH = library/libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I ./includes -I $(LIBFT_PATH)
CFLAGS = -g -Wall -Wextra -Werror $(includes)

SRCS = moves.c moves2.c order.c main.c utils.c
OBJS = $(addprefix sources/,$(SRCS:%.c=%.o))

RM = rm -f

all: libft $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		cc $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $@

libft:
	make -C $(LIBFT_PATH)