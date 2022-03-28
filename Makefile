# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:30:13 by mahmad-j          #+#    #+#              #
#    Updated: 2022/03/28 16:47:44 by mahmad-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	server.c client.c
OBJ		=	$(SRC:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all		:	server client

bonus	:	server client

server	:	server.o libft
			$(CC) -o $@ $< -Llibft -lft

client	:	client.o libft
			$(CC) -o $@ $< -Llibft -lft

%.o		:	%.c
			$(CC) $(CFLAGS) -c $?

libft	:
			make -C libft

clean	:
			rm -f $(OBJ)
			make -C libft clean

fclean	:	clean
			rm -f server client libft/libft.a
			
re		:	fclean all

.PHONY	:	all bonus libft clean fclean re