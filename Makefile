# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 18:07:38 by Hadia             #+#    #+#              #
#    Updated: 2025/03/12 18:07:55 by Hadia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./include 

CLIENT_SIGNAL = ft_client_signals.c
SERVER_SIGNAL = ft_server_signals.c
SERVER = server.c $(SERVER_SIGNAL)
CLIENT = client.c $(CLIENT_SIGNAL)

SERVER_SRC = $(SERVER)
SERVER_OBJ = $(SERVER:.c=.o)

CLIENT_SRC = $(CLIENT)
CLIENT_OBJ = $(CLIENT:.c=.o)

OBJS = $(CLIENT_OBJ) $(SERVER_OBJ)

SERVER_NAME = server
CLIENT_NAME = client
NAME = server

all: $(NAME)

LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a

$(NAME): ft_server ft_client 

$(LIBFT): FORCE
	make -C $(LIBDIR)

ft_server: $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)

ft_client: $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)

clean:
	rm -rf $(OBJS)
	cd $(LIBDIR) && $(MAKE) clean

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	cd $(LIBDIR) && $(MAKE) fclean

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDE)-c $< -o $@

re: fclean all

.PHONY: all minitalk server client clean fclean re libft

FORCE:

