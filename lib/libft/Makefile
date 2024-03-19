NAME=libft.a

CFLAGS= -Wall -Werror -Wextra

CC= cc

SRCS=  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		 ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		 ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		 ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		 ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		 get_next_line.c get_next_line_utils.c get_next_line_utilsb.c\
		 ft_printpercent.c ft_print_prefix.c ft_print_s.c ft_print_p.c\
		 ft_print_c.c ft_printf.c ft_print_numbase.c ft_strlen.c ft_strnstr.c\
		 ft_strncmp.c ft_checkerror.c ft_checkerror_malloc.c ft_print_checkspace.c\
		 ft_getprintlength.c ft_get_args.c ft_handle_errors.c

BONUS_C= ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstadd_back.c \
		 ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		 get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS= $(SRCS:.c=.o)

BOBJS= $(BONUS_C:.c=.o)

RM= rm -f

LB= ar rcs

all:	$(NAME)

$(NAME): $(OBJS)
	@$(LB) $(NAME) $(OBJS)

bonus: $(OBJS) $(BOBJS)
	$(LB) $(NAME) $(BOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
