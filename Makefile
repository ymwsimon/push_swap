NAME = push_swap

OBJS = $(SRCS_SHARE:=.o)

BONUS = checker

BONUS_SRCS = checker checker_utils

OBJS_B = $(BONUS_SRCS:=.o)

SRCS_SHARE = init_des push rank rotate small_solve solve chunk_solve swap utils chunk_solve_logic chunk_solve_utils

FLAGS = -Wall -Wextra -Werror

CC = cc

INC_DIR = ./includes

SRCS_DIR = ./srcs

all : $(NAME)

$(NAME) : $(OBJS) $(NAME:=.o) 
	$(CC) $(FLAGS) -o $(NAME) $^ -I$(INC_DIR)

$(OBJS) : $(SRCS_SHARE:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $^ -I$(INC_DIR)

$(NAME:=.o) : $(NAME:%=$(SRCS_DIR)/%.c) $(SRCS_SHARE:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $^ -I$(INC_DIR)

bonus : $(OBJS_B) $(OBJS)
	$(CC) $(FLAGS) -o $(BONUS) $(OBJS_B) $(OBJS) -I$(INC_DIR)

$(OBJS_B) : $(BONUS_SRCS:%=$(SRCS_DIR)/%.c) $(SRCS_SHARE:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $^ -I$(INC_DIR)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : clean $(NAME)

.PHONY : all clean fclean re bonus
