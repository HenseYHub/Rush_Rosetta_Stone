NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
	ft_process.c \
	ft_utils.c \
	file_reader.c \
	parser_dict.c 


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c header_02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
