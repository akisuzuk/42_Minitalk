# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 21:02:43 by akisuzuk          #+#    #+#              #
#    Updated: 2023/11/12 21:10:18 by akisuzuk         ###   ########.fr        #
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

$(NAME) : $(C_OBJ) $(S_OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(C_OBJ) $(LIB) -o $(C_NAME)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIB) -o $(S_NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(C_OBJ) $(S_OBJ) $(BONUS_C_OBJ) $(BONUS_S_OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(C_NAME) $(S_NAME)

re : fclean all

.PHONEY : all clean fclean re bonus
