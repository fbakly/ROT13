CC	:= gcc

RM	:= rm -rf

LDFLAGS	+= -L. -lmy

CFLAGS	+= -Iinclude

SRCS	:= $(wildcard *.c)

OBJS	:= $(SRCS:.c=.o)

NAME	:= rot13

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
