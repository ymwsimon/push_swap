NAME = push_swap

OBJS = $(SRCS_SHARE:=.o)

BONUS = checker 

OBJS_B = $(BONUS:=.o)

SRCS_SHARE = init_des push rank rotate small_solve solve chunk_solve swap utils

FLAGS = -Wall -Wextra -Werror

CC = cc

INC_DIR = ./includes

SRCS_DIR = ./srcs

LIBFT_DIR = ./libft

LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(NAME:=.o) 
	$(CC) $(FLAGS) -o $(NAME) $^ -I$(INC_DIR)

$(OBJS) : $(SRCS_SHARE:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $^ -I$(INC_DIR)

$(NAME:=.o) : $(NAME:%=$(SRCS_DIR)/%.c) $(SRCS_SHARE:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $^ -I$(INC_DIR)

bonus : $(OBJS_B) $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(FLAGS) -o $(BONUS) $(OBJS_B) $(OBJS) -I$(INC_DIR) -lft -L$(LIBFT_DIR)

$(OBJS_B) : $(BONUS:%=$(SRCS_DIR)/%.c) $(SRCS_SHARE:%=$(SRCS_DIR)/%.c)
	$(CC) $(FLAGS) -c $^ -I$(INC_DIR) -I$(LIBFT_DIR)

$(LIBFT_DIR)/$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -rf *.o

fclean : clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re : clean $(NAME)

.PHONY : all clean fclean re bonus
