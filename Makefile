NAME = cub3D
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lz
MATH_FLAG = -lm
INCLUDE_DIR = include
RM = rm -f
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_DIR)$(LIBFT_NAME)
#change the folder name from minilibx-linux to mlx_linux
MLX_DIR = mlx-linux/
MLX_NAME = libmlx.a
MLX	 = $(MLX_DIR)$(MLX_NAME)
PURPLE = \033[1;35m
CYAN = \033[1;36m
UNDERLINED_PURPLE = \033[4;35m
RESET = \033[0m

SRC_FILES = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing_map.c \
		$(SRC_DIR)/parsing_exit_functions.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/free_functions.c \
		$(SRC_DIR)/check_file_extension.c \
		$(SRC_DIR)/check_elements.c \
		$(SRC_DIR)/read_validate_map.c \
		$(SRC_DIR)/check_borders.c \
		$(SRC_DIR)/player_moves.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: libft mlx $(NAME)

libft:
	@echo "$(PURPLE)Making libft...$(RESET)"
	@make -sC $(LIBFT_DIR)

#to run the configure into it added "cd mlx-linux && ./configure"
mlx:
	@echo "$(PURPLE)Making mlx...$(RESET)"
	@if [ -f $(MLX_DIR)/configure ] && [ ! -x $(MLX_DIR)/configure ]; then \
		echo "$(CYAN)Setting executable permission for configure...$(RESET)"; \
		chmod +x $(MLX_DIR)/configure; \
	fi
	@if [ -x $(MLX_DIR)/configure ]; then cd $(MLX_DIR) && ./configure; fi
	@make -sC $(MLX_DIR)

$(NAME): $(OBJ_FILES)
	@echo "$(PURPLE)Building...$(RESET)"
	@$(CC) $^ -o $@ $(INCLUDE) $(LIBFT) $(MLX) $(MLX_FLAGS) $(MATH_FLAG)
	@echo "$(PURPLE)$(NAME) compiled successfully.$(RESET)"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(PURPLE)Compiling $(UNDERLINED_PURPLE)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

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
