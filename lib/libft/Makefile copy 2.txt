NAME=libftprintf.a

CFLAGS= -Wall -Werror -Wextra

CC= cc

SRCS=  ft_printpercent.c ft_print_prefix.c ft_print_s.c ft_print_p.c\
		ft_print_c.c ft_printf.c ft_print_numbase.c ft_strlen.c ft_strnstr.c\
		ft_strncmp.c ft_checkerror.c ft_checkerror_malloc.c ft_print_checkspace.c\
		ft_getprintlength.c ft_get_args.c

OBJS= $(SRCS:.c=.o)

RM= rm -f

LB= ar rcs

all:	$(NAME)

$(NAME): $(OBJS)
	@$(LB) $(NAME) $(OBJS)

bonus:	all

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
