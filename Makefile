NAME = cub3D
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDE_DIR)
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
INCLUDE_DIR = include
RM = rm -f
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
PURPLE = \033[1;35m
CYAN = \033[1;36m
UNDERLINED_PURPLE = \033[4;35m
RESET = \033[0m

SRC_FILES = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing_map.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: libft mlx $(NAME)

libft:
	@echo "$(PURPLE)Making libft...$(RESET)"
	@make -C $(LIBFT_DIR)
mlx:
	@echo "$(PURPLE)Making mlx...$(RESET)"
	@make -C $(MLX_DIR)

$(NAME): $(OBJ_FILES)
	@echo "$(PURPLE)Building...$(RESET)"
	$(CC) $^ -o $@ -L$(LIBFT_DIR) -lft $(MLX_FLAGS)
	@echo "$(PURPLE)$(NAME) compiled successfully.$(RESET)"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	echo "$(PURPLE)Compiling $(UNDERLINED_PURPLE)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(PURPLE)Cleaning up...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJ_FILES)
	@if [ -d "$(OBJ_DIR)" ]; then rm -rf $(OBJ_DIR); fi
	@echo "$(PURPLE)Clean complete!$(RESET)"

fclean: clean
	@echo "$(PURPLE)Removing  \033[9m$(NAME)$(RESET)"
	@rm -f $(NAME)
	@echo "$(CYAN)Removing  \033[9m$(LIBFT_DIR)/libft.a$(RESET)"
	@rm -f $(LIBFT_DIR)/libft.a
	@echo "$(PURPLE)Removing complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re libft
