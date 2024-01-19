NAME := push_swap

SRCS_SHARE := init_des push rank rotate small_solve chunk_solve swap utils chunk_solve_logic chunk_solve_utils input_prepare ft_split

BONUS := checker

SRCS_BONUS := checker checker_utils

FLAGS := -Wall -Wextra -Werror

CC := cc

INC_DIR := includes

SRCS_DIR := srcs

OBJ_DIR := obj

OBJS_MAND := $(NAME:%=$(OBJ_DIR)/%.o)

OBJS_MAND += $(SRCS_SHARE:%=$(OBJ_DIR)/%.o)

OBJS_BONUS := $(SRCS_BONUS:%=$(OBJ_DIR)/%.o)

OBJS_BONUS += $(SRCS_SHARE:%=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS_MAND)
	$(CC) $(FLAGS) $^ -I$(INC_DIR) -o $@

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $^ -I$(INC_DIR) -o $@

bonus : $(OBJS_BONUS)
	$(CC) $(FLAGS) $^ -I$(INC_DIR) -o $(BONUS)

clean :
	rm -rf *.o
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : clean all

.PHONY : all clean fclean re bonus
