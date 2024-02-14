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

# Source Files
SRCS			:= 	$(SRC_DIR)main.c \
					$(SRC_DIR)search_path.c \
					$(SRC_DIR)ft_split_concat.c


# Creation of Object Files for each Source File
OBJ				:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Rules
all: 		${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(@D)
				@${CC} ${CFLAGS} -I.libs/libft -c $? -o $@


${NAME}: ${OBJ}
				@make -C ./libs/libft
				@${CC} ${CFLAGS} $^ -L./libs/libft -lft -o ${NAME}

libft:
				@make -C libs/libft


clean:
				@make clean -C ./libs/libft
				@${RM} ${OBJ}

fclean:			clean
				@${RM} ${NAME}
				@${RM} ./libs/libft/libft.a
				@rm -rf ${OBJ_DIR}

re:				fclean all

.PHONY: all clean fclean re libft