CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./lib/libft/libft.a
RM = rm -rf

SERVER = server
CLIENT = client

SV_SRCS = src/server.c
SV_OBJS = $(SV_SRCS:.c=.o)

CLIENT_SRCS = src/client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

MAKE_LIBR = make --no-print-directory -C

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV_BONUS_SRCS = src_bonus/server_bonus.c
SV_BONUS_OBJS = $(SV_BONUS_SRCS:.c=.o)

CLIENT_BONUS_SRCS = src_bonus/client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE_LIBR) ./lib/libft
$(SERVER): $(SV_OBJS)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client

$(SERVER_BONUS): $(SV_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SV_BONUS_OBJS) $(LIBFT) -o server_bonus
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./lib/libft
	$(RM) $(SV_OBJS) $(CLIENT_OBJS)
	$(RM) $(SV_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C ./lib/libft
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)	

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
