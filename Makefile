# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 13:53:49 by baguiar-          #+#    #+#              #
#    Updated: 2024/09/03 13:53:49 by baguiar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC	= 

OBJS = $(SRC:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAG = -fsanitize=thread -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re