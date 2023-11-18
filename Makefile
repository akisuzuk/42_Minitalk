# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 21:02:43 by akisuzuk          #+#    #+#              #
#    Updated: 2023/11/18 12:33:16 by akisuzuk         ###   ########.fr        #
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

$(NAME) : $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJ) $(LIB)
#	$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(LIB)
	$(CC) $(C_OBJ) -o $(C_NAME) $(LIB)

$(S_NAME): $(S_OBJ) $(LIB)
#	$(CC) $(CFLAGS) $(S_OBJ) -o $(S_NAME) $(LIB)
	$(CC) $(S_OBJ) -o $(S_NAME) $(LIB)

$(LIB):
	$(MAKE) -C ./libft


.c.o :
#	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)
	$(CC) -c $< -o $(<:.c=.o) $(HEAD)

clean :
	$(RM) $(C_OBJ) $(S_OBJ)

fclean : clean
	$(RM) $(C_NAME) $(S_NAME)

re : fclean all

.PHONEY : all clean fclean re bonus
