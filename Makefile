# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:56:15 by pabeckha          #+#    #+#              #
#    Updated: 2024/02/29 11:16:42 by pabeckha         ###   ########.fr        #
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

# =============================================================================
# Color Variables
# =============================================================================

BLACK				= 		"\033[0;30m"
GRAY				= 		"\033[1;30m"
RED					=		"\033[0;31m"
GREEN				=		"\033[0;32m"
YELLOW				=		"\033[1;33m"
PURPLE				=		"\033[0;35m"
CYAN				=		"\033[0;36m"
WHITE				=		"\033[1;37m"
EOC					=		"\033[0;0m"
LINE_CLEAR			=		"\x1b[1A\x1b[M"






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


SHARED_SRCS		:= 	$(SRC_DIR)store_commands.c \
					$(SRC_DIR)store_commands_utils.c \
					$(SRC_DIR)search_path.c \
					$(SRC_DIR)command_split_concat.c \
					$(SRC_DIR)command_split_concat_utils.c \
					$(SRC_DIR)pipex_utils.c \
					$(SRC_DIR)pipex_utils_2.c \
					$(SRC_DIR)pipex_utils_3.c \
					$(SRC_DIR)pipex_utils_4.c \
					$(SRC_DIR)free_variables.c \
					$(SRC_DIR)store_arguments.c \


# Source Files
# SRCS			:= 	$(SRC_DIR)pipex.c \
# 					$(SHARED_SRCS) \


# SRCS_BONUS		:= 	$(SRC_DIR)pipex_bonus.c \
# 					$(SRC_DIR)pipex_bonus_utils.c \
# 					$(SHARED_SRCS)\
					
SRCS			:= 	$(SRC_DIR)pipex.c \
					$(SRC_DIR)pipex_bonus_utils.c \
					$(SHARED_SRCS)\

# Creation of Object Files for each Source File
OBJ				:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Creation of Object Files for each Bonus Source File
OBJ_BONUS		:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

# Rules
all: 		${NAME}

bonus: 		${NAME}_bonus


$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
					@mkdir -p $(@D)
					@${CC} ${CFLAGS} -I.libs/libft -c $? -o $@


${NAME}: 		${OBJ}
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building pipex for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@make -s -C ./libs/libft
					@${CC} ${CFLAGS} $^ -L./libs/libft -lft -o ${NAME}
					@echo $(GREEN) "Pipex Mandatory is created!\n" $(EOC)

${NAME}_bonus:	${OBJ_BONUS}
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building pipex for" $(YELLOW) "Bonus" $(WHITE)
					@make -s -C ./libs/libft
					@${CC} ${CFLAGS} $^ -L./libs/libft -lft -o ${NAME}_bonus
					@echo $(GREEN) "Pipex Bonus is created!\n" $(EOC)

libft:
				@make -C libs/libft


clean:
				@echo $(YELLOW) "Cleaning object files..." $(EOC)
				@make -s clean -C ./libs/libft
				@${RM} ${OBJ} ${OBJ_BONUS}
				@echo $(RED) "Object files are cleaned!\n" $(EOC)

fclean:			clean
				@echo $(YELLOW) "Removing pipex..." $(EOC)
				@${RM} ${NAME} ${NAME}_bonus
				@${RM} ./libs/libft/libft.a
				@rm -rf ${OBJ_DIR}
				@echo $(RED) "pipex is removed!\n" $(EOC)

re:				fclean all



.PHONY: all clean fclean re libft bonus