CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = extra_functions_1.c \
       extra_functions_2.c \
       extra_functions_3.c \
       extra_functions_4.c \
       ft_push.c \
       ft_reverse_rotate.c \
       ft_rotate.c \
       ft_swap.c \
       push_swap_main.c \
       push_swap.c \
       sort_data_big.c \
       sort_data_small.c \
       sort_data.c

OBJECTS = $(SRCS:.c=.o)

HEADERS = -I include

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
