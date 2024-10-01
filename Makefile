# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 12:05:48 by baguiar-          #+#    #+#              #
#    Updated: 2024/09/19 10:16:53 by baguiar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ar rcs $@ $^ is the recipe or command to build the target. 
# ar: Archive command used for creating static libraries.
# rcs: Options for ar:
#     r: Insert files into the archive.
#     c: Create the archive if it doesn't exist.
#     s: Write an index (symbol table) into the archive.
# $@: Automatic variable representing the target name
# $^: Automatic variable representing all the prerequisites(the object files)
# @: supress the echoing command that follows the command execution.
# := The value of the variable is evaluated immediately when the assignement is made,
# it does not change later even if other variables it depends on are modified afterward.

#----Color Vars-----#
BLACK				= 		"\033[0;30m"
GRAY				= 		"\033[1;30m"
RED					=		"\033[0;31m"
GREEN				=		"\033[0;32m"
YELLOW				=		"\033[1;33m"
PURPLE				=		"\033[0;35m"
CYAN				=		"\033[0;36m"
WHITE				=		"\033[1;37m"
EOC					=		"\033[0;0m"
RESET_COLOR 		= 		"\033[0m"

NAME = philo

SRC_DIR		:= src/
OBJ_DIR		:= obj/

CC := cc
RM := rm -f
CFLAGS := -Wall -Werror -Wextra -pthread
#DEBUGFLAG = -fsanitize=thread -g

SRC	:= 	control.c \
		main.c	\
		philo_cycle.c \
		philos_init.c \
		routine.c \
		simulation.c \
		utils_args.c \
		utils_mutex.c \
		utils_routine.c \
		utils.c \

SRCS := $(addprefix $(SRC_DIR), $(SRC))

OBJ := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: ${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@echo $(YELLOW) "Compiling...\t" $< $(EOC)
		@mkdir -p $(@D)
		@${CC} ${CFLAGS} -c $? -o $@

${NAME}:	${OBJ}
		@echo $(GREEN) "Compiled!\n" $(EOC)
		@echo $(WHITE) "Building ${NAME} for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
		@${CC} ${CFLAGS} $^ -o ${NAME}
		@echo $(GREEN) "${NAME} Mandatory is created!\n" $(EOC) $(RESET_COLOR)


clean:
	@echo $(YELLOW) "Cleaning object files...\n" $(EOC)
	@${RM} ${OBJ}
	@echo $(RED) "Object files are cleaned!\n" $(EOC)

fclean: clean
	@echo $(YELLOW) "Removing ${NAME}..." $(EOC)
	@${RM} ${NAME}
	@rm -rf ${OBJ_DIR}
	@echo $(RED) "${NAME} is removed!\n" $(EOC)

re: fclean all

.PHONY: all clean fclean re
