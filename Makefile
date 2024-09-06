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

SRC	= 	philo.c \
		args_init.c \
		check.c	\
		control.c \
		free.c \
		monitor_philo.c \
		philos_init.c \
		time.c \
		utils.c

OBJS = $(SRC:.c=.o)

CC = cc
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