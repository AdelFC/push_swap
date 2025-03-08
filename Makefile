CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

FT_PRINTF_DIR = lib/ftprintf
GNL_DIR = lib/get_next_line
LIBFT_DIR = lib/libft
UTILS_DIR = utils
SRC_DIR = src
OBJ_DIR = obj
INCS = -I includes

SRC = check_args2.c check_args.c \
	swap.c push.c rotate.c \
	reverse_rotate.c push_swap.c \
	init.c index.c sort.c \
	sort2.c sort_algo1.c \
	sort_algo2.c sort_algo3.c

UTILS = ft_stackadd_back.c ft_stackclear.c \
    ft_stackiter.c ft_stacknew.c \
    ft_stackadd_front.c ft_stackdelone.c \
    ft_stacklast.c ft_stacksize.c \
    ft_atol.c ft_stack_min.c \
	ft_stack_max.c ft_abs.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o) $(UTILS:.c=.o))

LIBS = -L$(FT_PRINTF_DIR) -lftprintf \
       -L$(GNL_DIR) -lftgnl \
       -L$(LIBFT_DIR) -lft

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m

all: $(FT_PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN) Compilation of $(NAME) completed!$(BLUE)"

$(FT_PRINTF_DIR)/libftprintf.a:
	@make -C $(FT_PRINTF_DIR) --no-print-directory

$(GNL_DIR)/libgnl.a:
	@make -C $(GNL_DIR) --no-print-directory

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW) Created directory: $(OBJ_DIR)$(BLUE)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@make -C $(GNL_DIR) clean --no-print-directory
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(YELLOW) Cleaned object files.$(BLUE)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@make -C $(GNL_DIR) fclean --no-print-directory
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(YELLOW) Removed $(NAME) and compiled files.$(BLUE)"

re: fclean all

.PHONY: all clean fclean re
