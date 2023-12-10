NAME = push_swap

NAME_MAIN = push_swap

SRCS = init_des push rank rotate small_solve solve chunk_solve swap utils

OBJS = $(SRCS:=.o)

OBJS_MAIN = $(NAME_MAIN:=.o)

BONUS = checker 

OBJS_B = $(BONUS:=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

INC_DIR = ./includes

SRCS_DIR = ./srcs

NAME_B = checker

LIBFT_DIR = ./libft

LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(OBJS_MAIN) -I$(INC_DIR)

$(OBJS) : $(SRCS:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $(SRCS:%=$(SRCS_DIR)/%.c) -I$(INC_DIR)

$(OBJS_MAIN) : $(NAME_MAIN:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $(NAME_MAIN:%=$(SRCS_DIR)/%.c) -I$(INC_DIR)

bonus : $(OBJS) $(OBJS_B) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(FLAGS) -o $(NAME_B) $(OBJS) $(OBJS_B) -I$(INC_DIR) -lft -L$(LIBFT_DIR)

$(OBJS_B) : $(BONUS:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $(BONUS:%=$(SRCS_DIR)/%.c) -I$(INC_DIR) -I$(LIBFT_DIR)

$(LIBFT_DIR)/$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : clean $(NAME)

.PHONY : $(NAME) all clean fclean re bonus $(BONUS)
