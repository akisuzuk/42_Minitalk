# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 21:02:43 by akisuzuk          #+#    #+#              #
#    Updated: 2023/12/03 15:52:41 by akisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
C_NAME = client
S_NAME = server
C_SRC = ft_client.c
S_SRC = ft_server.c
LIB = ./libft/libft.a
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = -I ./includes
RM = rm -f

all : $(NAME)

#$(NAME) : $(C_OBJ) $(S_OBJ)
#	$(MAKE) -C ./libft
#	$(CC) $(CFLAGS) $(C_OBJ) $(LIB) -o $(C_NAME)
#	$(CC) $(CFLAGS) $(S_OBJ) $(LIB) -o $(S_NAME)
# 下記のように修正

#libftはそのまま全部のファイルぶっ込んで個別にmakeするようにすると、関数のアプデした時に楽
$(LIB):
	$(MAKE) -C ./libft

$(NAME) : $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(LIB)

$(S_NAME): $(S_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(S_OBJ) -o $(S_NAME) $(LIB)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)

clean :
	$(RM) $(C_OBJ) $(S_OBJ)

fclean : clean
	$(RM) $(C_NAME) $(S_NAME)

re : fclean all

.PHONEY : all clean fclean re bonus
