# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:56:15 by pabeckha          #+#    #+#              #
#    Updated: 2024/03/02 12:00:29 by pabeckha         ###   ########.fr        #
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
RESET_COLOR 		= 		"\033[0m"


# Standard
NAME			= pipex

# Directories
SRC_DIR			:= src/
OBJ_DIR			:= obj/

# Compiler and Flags
CC				:= cc
SANITIZER 		:= # -fsanitize=address -g
RM				:= rm -f
# CFLAGS			:= -Wall -Wextra -Werror

# Libraries
LIBFT			:= ./libs/libft/libft.a


SHARED_SRCS		:= 	$(SRC_DIR)store_commands.c \
					$(SRC_DIR)store_commands_utils.c \
					$(SRC_DIR)get_path_env.c \
					$(SRC_DIR)command_split_concat.c \
					$(SRC_DIR)command_split_concat_utils.c \
					$(SRC_DIR)store_main_arguments.c \
					$(SRC_DIR)ft_free.c \
					$(SRC_DIR)get_number_commands.c \
					$(SRC_DIR)store_command_full_string.c \
					$(SRC_DIR)allocate_memory_commands.c \
					$(SRC_DIR)store_path_commands.c \
					$(SRC_DIR)store_variables.c \
					$(SRC_DIR)open_input_output_fds.c \
					$(SRC_DIR)create_pipes.c \
					$(SRC_DIR)close_pipes_parent.c \
					$(SRC_DIR)close_pipes_child.c \
					$(SRC_DIR)allocate_memory_pid.c \
					$(SRC_DIR)create_child_processes.c \
					$(SRC_DIR)wait_child_processes.c \
					$(SRC_DIR)execute_commands.c \
					$(SRC_DIR)redirect_fds_child.c \
					$(SRC_DIR)allocate_memory_path_commands.c \
					$(SRC_DIR)get_path_command.c \
					$(SRC_DIR)pipex_utils.c \


#Source Files
SRCS			:= 	$(SRC_DIR)pipex.c \
					$(SHARED_SRCS) \


SRCS_BONUS		:= 	$(SRC_DIR)pipex_bonus.c \
					$(SRC_DIR)pipex_bonus_utils.c \
					$(SHARED_SRCS)\
					
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
					@echo $(YELLOW) "Compiling...\t" $< $(EOC)
					@mkdir -p $(@D)
					@${CC} ${CFLAGS} $(SANITIZER) -I.libs/libft -c $? -o $@


${NAME}: 		${OBJ}
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building pipex for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@make -s -C ./libs/libft
					@${CC} ${CFLAGS} $(SANITIZER) $^ -L./libs/libft -lft -o ${NAME}
					@echo $(GREEN) "Pipex Mandatory is created!\n" $(EOC)
					@echo $(RED) "REMEMBER TO UNCOMMENT CC FLAGS" $(RESET_COLOR)

${NAME}_bonus:	${OBJ_BONUS}
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building pipex for" $(YELLOW) "Bonus" $(WHITE)
					@make -s -C ./libs/libft
					@${CC} ${CFLAGS} $^ -L./libs/libft -lft -o ${NAME}_bonus
					@echo $(GREEN) "Pipex Bonus is created!\n" $(EOC) $(RESET_COLOR)

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