# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:56:15 by pabeckha          #+#    #+#              #
#    Updated: 2024/02/22 19:03:43 by pabeckha         ###   ########.fr        #
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



# ar rcs $@ $^ is the recipe or command to build the target. 
# ar: Archive command used for creating static libraries.
# rcs: Options for ar:
#     r: Insert files into the archive.
#     c: Create the archive if it doesn't exist.
#     s: Write an index (symbol table) into the archive.
# $@: Automatic variable representing the target name
# $^: Automatic variable representing all the prerequisites(the object files)

# Standard
NAME			= pipex

# Directories
SRC_DIR			:= src/
OBJ_DIR			:= obj/

# Compiler and Flags
CC				:= cc
RM				:= rm -f
#CFLAGS			:= -Wall -Wextra -Werror

# Libraries
LIBFT			:= ./libs/libft/libft.a


SHARED_SRCS		:= 	$(SRC_DIR)search_path.c \
					$(SRC_DIR)command_split_concat.c \


# Source Files
SRCS			:= 	$(SRC_DIR)pipex.c \
					$(SHARED_SRCS) \
					# $(SRC_DIR)search_path.c \
					# $(SRC_DIR)command_split_concat.c \


SRCS_BONUS		:= 	$(SRC_DIR)pipex_bonus.c \
$					$(SHARED_SRCS) \

# Creation of Object Files for each Source File
OBJ				:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Creation of Object Files for each Bonus Source File
OBJ_BONUS		:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

# Rules
all: 		${NAME}

bonus: 		${NAME}_bonus

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@${CC} ${CFLAGS} -I.libs/libft -c $? -o $@


${NAME}: 		${OBJ}
					@make -C ./libs/libft
					@${CC} ${CFLAGS} $^ -L./libs/libft -lft -o ${NAME}

${NAME}_bonus:	${OBJ_BONUS}
					@make -C ./libs/libft
					@${CC} ${CFLAGS} $^ -L./libs/libft -lft -o ${NAME}_bonus
				

libft:
				@make -C libs/libft


clean:
				@make clean -C ./libs/libft
				@${RM} ${OBJ} ${OBJ_BONUS}

fclean:			clean
				@${RM} ${NAME} ${NAME}_bonus
				@${RM} ./libs/libft/libft.a
				@rm -rf ${OBJ_DIR}

re:				fclean all

	

.PHONY: all clean fclean re libft bonus