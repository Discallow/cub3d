NAME = cub3D
BONUS = 0
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# Minilibx
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

SRC_PATH = src/
OBJ_PATH = obj/
OBJ_DIR = $(OBJ_PATH)src/

# Colors
PURPLE = \033[1;35m
CYAN = \033[1;36m
UNDERLINED_PURPLE = \033[4;35m
RESET = \033[0m

SRC = $(SRC_PATH)main.c \
      $(SRC_PATH)parsing_map.c \
      $(SRC_PATH)parsing_exit_functions.c \
      $(SRC_PATH)utils.c \
      $(SRC_PATH)exit_functions.c \
      $(SRC_PATH)check_file_extension.c \
      $(SRC_PATH)check_elements.c \
      $(SRC_PATH)read_validate_map.c \
      $(SRC_PATH)check_borders.c \
      $(SRC_PATH)player_moves.c \
      $(SRC_PATH)drawing.c \
      $(SRC_PATH)raycasting.c \
      $(SRC_PATH)load_textures.c \
      $(SRC_PATH)weapon.c \
      $(SRC_PATH)enemy.c \
      $(SRC_PATH)check_rotation_door.c \
      $(SRC_PATH)check_wall_door_texture.c \
      $(SRC_PATH)enemy_death.c \
      $(SRC_PATH)raycasting_calcs.c \
      $(SRC_PATH)doors.c \
      $(SRC_PATH)raycasting_calcs_untextured.c \
      $(SRC_PATH)raycasting_calcs_textured.c \
      $(SRC_PATH)mouse_hooks.c \
      $(SRC_PATH)minimap.c \
      $(SRC_PATH)utils2.c \
      $(SRC_PATH)key_hooks.c \
      $(SRC_PATH)crosshair.c

OBJS = $(SRC:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)

INC = -I ./include/ -I ./libft/ -I ./minilibx-linux/

all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

# Create object directories
$(OBJ_PATH):
	@mkdir -p $(OBJ_DIR)

# Object rule
$(OBJ_DIR)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(INC) -c $< -o $@

# Main program rule
$(NAME): $(OBJS)
	@echo "$(PURPLE)Building...$(RESET)"
	@$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm
	@echo "$(PURPLE)$(NAME) compiled successfully.$(RESET)"

# Libft rule
$(LIBFT):
	@echo "$(PURPLE)Making libft...$(RESET)"
	@make -sC $(LIBFT_PATH)

#to run the configure into it added "cd mlx-linux && ./configure"
$(MLX):
	@echo "$(PURPLE)Making mlx...$(RESET)"
	@if [ -f $(MLX_PATH)/configure ] && [ ! -x $(MLX_PATH)/configure ]; then \
		echo "$(CYAN)Setting executable permission for configure...$(RESET)"; \
		chmod +x $(MLX_PATH)/configure; \
	fi
	@make -sC $(MLX_PATH)

bonus:
	@echo "$(PURPLE)Building with bonus...$(RESET)"
	@$(MAKE) BONUS=1 all

clean:
	@echo "$(PURPLE)Cleaning up...$(RESET)"
	@rm -rf $(OBJ_PATH)
	@make -sC $(LIBFT_PATH) clean
	@make -sC $(MLX_PATH) clean
	@echo "$(PURPLE)Clean complete!$(RESET)"

fclean: clean
	@echo "$(PURPLE)Removing  \033[9m$(NAME)$(RESET)"
	@rm -f $(NAME)
	@echo "$(CYAN)Removing  \033[9m$(LIBFT_DIR)/libft.a$(RESET)"
	@make -sC $(LIBFT_PATH) fclean
	@echo "$(PURPLE)Removing complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

