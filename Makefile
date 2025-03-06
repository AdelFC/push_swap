CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

# Directories
FT_PRINTF_DIR = lib/ftprintf
GNL_DIR = lib/get_next_line
LIBFT_DIR = lib/libft
UTILS_DIR = utils
SRC_DIR = src
INCS = -I includes

# Source files
SRC = $(SRC_DIR)/ft_errors.c $(SRC_DIR)/check_args.c \
	$(SRC_DIR)/swap.c $(SRC_DIR)/push.c $(SRC_DIR)/rotate.c \
	$(SRC_DIR)/reverse_rotate.c $(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/init.c $(SRC_DIR)/index.c $(SRC_DIR)/sort.c \
	$(SRC_DIR)/sort2.c $(SRC_DIR)/sort_algo1.c \
	$(SRC_DIR)/sort_algo2.c $(SRC_DIR)/sort_algo3.c \

UTILS = $(UTILS_DIR)/ft_stackadd_back.c $(UTILS_DIR)/ft_stackclear.c \
    $(UTILS_DIR)/ft_stackiter.c $(UTILS_DIR)/ft_stacknew.c \
    $(UTILS_DIR)/ft_stackadd_front.c $(UTILS_DIR)/ft_stackdelone.c \
    $(UTILS_DIR)/ft_stacklast.c $(UTILS_DIR)/ft_stacksize.c \
    $(UTILS_DIR)/ft_atol.c $(UTILS_DIR)/ft_stack_min.c \
	$(UTILS_DIR)/ft_stack_max.c $(UTILS_DIR)/ft_abs.c\

# Object files
OBJS = $(SRC:.c=.o) $(UTILS:.c=.o)

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m

all: $(FT_PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF_DIR) -lftprintf \
        -L$(GNL_DIR) -lftgnl -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!"

# Libraries
$(FT_PRINTF_DIR)/libftprintf.a:
	@make -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "$(CYAN)libftprintf compiled!"

$(GNL_DIR)/libgnl.a:
	@make -C $(GNL_DIR) --no-print-directory
	@echo "$(CYAN)get_next_line compiled!"

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "$(CYAN)libft compiled!"

# Rules
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@make -C $(GNL_DIR) clean --no-print-directory
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(BLUE)Object files cleaned!"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@make -C $(GNL_DIR) fclean --no-print-directory
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(BLUE)All compiled files cleaned!"

re: fclean all
	@echo "$(GREEN)Project fully rebuilt!"

n:
	@norminette -R CheckDefine
	@echo "$(YELLOW)Norminette check completed!"

.PHONY: all clean fclean re
