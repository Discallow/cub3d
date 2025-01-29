/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:40 by discallow         #+#    #+#             */
/*   Updated: 2025/01/29 17:54:06 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <math.h>//math functions, need -lm to compile
/*# include <stdint.h>//to use uint32_t, int > 0 with 32 bits */
					/*(0 a 4.294.967.295 (2^32 - 1))*/

# define RESET		"\033[0m"
# define BOLD    	"\033[1m"
# define UNDERLINE 	"\033[4m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"

# define NEWLINE 		1
# define TILE_SIZE		32
# define M_PI			3.14159265358979323846
# define SCALE			40
# define NUM_TEXTURES 	12
# define VERTICAL		0
# define HORIZONTAL		1
# define WEAPON_SCALE	3
# define MILLISECOND	1000
# define ENEMY_SCALE	3
# define ROTATION_SPEED	0.05

# ifndef BONUS
#  define BONUS 1
# endif

# define ENEMY_TEXTURE				"textures/enemy.xpm"
# define ENEMY_DEAD_TEXTURE			"textures/enemy_dead.xpm"
# define DOOR_CLOSED_TEXTURE		"textures/door.xpm"
# define DOOR_OPEN1_TEXTURE			"textures/door2.xpm"
# define DOOR_OPEN2_TEXTURE			"textures/door3.xpm"
# define DOOR_OPEN3_TEXTURE			"textures/door4.xpm"
# define WEAPON_IDLE_TEXTURE		"textures/weapon_idle.xpm"
# define WEAPON_SHOOTING_TEXTURE	"textures/weapon_shooting.xpm"

typedef enum e_element
{
	CEILING,
	FLOOR,
}				t_element;

typedef struct s_position
{
	double	x;
	double	y;
	bool	move_w;
	bool	move_s;
	bool	move_a;
	bool	move_d;
	bool	rotate_right;
	bool	rotate_left;
	bool	open_door;
	bool	close_door;
	bool	shoot;
	bool	flag;
	char	dir;
	double	dir_x;
	double	dir_y;
	char	**rgb;
	int		color;
	int		total;
	void	*img;
	char	*path;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	double	angle;
	double	wall_dist;
	int		num;
}		t_position;

typedef struct s_map_copy
{
	int		line_index;
	bool	elements_filled;
	bool	map_read;
	int		max_width;
	int		max_height;
	char	*map_joined;
	int		player_num;
	int		enemy_num;
}				t_map_copy;

typedef struct s_calculation
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	last_ray_dir_x;
	double	last_ray_dir_y;
	double	plane_x;
	double	plane_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		wall_side;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	tex_y_step;
	double	tex_y_pos;
	int		tex_drawn;
	int		enemy_in;
	int		enemy_height;
	int		enemy_pos;
}				t_calculation;

typedef struct s_texture
{
	void	*tex;
	char	*data_addr;
	int		tex_width;
	int		tex_height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_texture;

typedef struct s_weapon
{
	int			draw_end_y;
	int			draw_start_y;
	double		tex_step[NUM_TEXTURES];
	int			tex_x;
}				t_weapon;

typedef struct s_enemy
{
	int			draw_end_y;
	int			draw_start_y;
	double		tex_step;
	int			tex_x;
	int			enemy_type;
	long		is_dead;
}				t_enemy;

typedef enum e_icon
{
	DOOR,
	PLAYER,
	ENEMIES,
}				t_icon;		

typedef enum e_textures_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	ENEMY,
	ENEMY_DEAD,
	DOOR_CLOSED,
	DOOR_OPEN1,
	DOOR_OPEN2,
	DOOR_OPEN3,
	WEAPON,
	WEAPON_SHOOTING,
}				t_textures_direction;

typedef struct s_mini_map
{
	int		start_i;
	int		start_j;
	int		end_i;
	int		end_j;
	float	player_x;
	float	player_y;
}				t_mini_map;

typedef struct s_crosshair
{
	int	line_length;
	int	thickness;
	int	x_start;
	int	y_start;
	int	y_start_vertical;
	int	y_end_vertical;
	int	x_start_horizontal;
	int	x_end_horizontal;
	int	height;
	int	width;
}				t_crosshair;

typedef struct s_game
{
	char			**map;
	t_position		north;
	t_position		south;
	t_position		west;
	t_position		east;
	int				len;
	int				x;
	int				y;
	int				fd;
	long			elapsed;
	t_map_copy		copy;
	t_mini_map		mini_map;
	t_crosshair		crosshair;
	t_position		player;
	t_position		door;
	t_position		wall;
	t_position		floor;
	t_position		ceiling;
	t_position		enemy;
	t_position		map2;
	void			*window;
	void			*connection;
	t_calculation	calc;
	t_texture		textures[NUM_TEXTURES];
	t_texture		tex_buff_data[NUM_TEXTURES];
	int				**tex_buff;
	t_weapon		weapon_data;
	t_enemy			enemy_data;
}				t_game;

char	*get_next_line(int fd);

/*PARSING*/
void	check_map(t_game *game, char *map);
void	return_invalid_color(char *str, t_game *game, char *line);
void	return_invalid_number_players(t_game *game, t_icon icon);
void	return_invalid_map(t_game *game);
void	return_invalid_line(t_game *game, char *line);
void	skip_spaces(char *line, size_t *i);
int		ft_atoi2(const char *s);
char	*ft_strjoin3(char *s1, char *s2);
int		ft_strcmp2(char *str1, char *str2);
int		check_extension(char *file);
void	check_image_extension(t_game *game);
void	open_file(t_game *game, char *file);
void	check_valid_line(char *line, t_game *game);
void	read_map(t_game *game);
char	*check_name(t_game *game, char *line, char *complete_line);
void	check_map_end(t_game *game, char *line);
void	check_borders(t_game *game, int x, int y);
void	check_door_borders(t_game *game, int x, int y);
void	check_if_map_closed(t_game *game, int x, int y);
void	check_first_last_line(t_game *game);

/*CLEANING ROUTINE*/
void	free_everything(t_game *game);
void	texture_error(t_game *game);
void	free_pixels_buffer(int **pixels_buffer, int height);
int		window_closed(t_game *game);

/*MOVES*/
void	redraw_map(t_game *game);
void	build_map(t_game *game);
int		key_pressed(int keysim, t_game *game);
int		key_released(int keysim, t_game *game);
void	move_backwards(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_forward(t_game *game);
void	rotate_right(t_game *game);
void	my_mlx_pixel_put(t_position *data, int x, int y, int color);
void	build_map(t_game *game);
void	rotate_left(t_game *game);
int		check_door(t_game *game, int x, int y, int flag);
long	gettime(void);

/*CALCULATIONS*/
void	ft_get_player_inicial_direction(t_game *game);
void	ft_ray_position(t_game *game, int x);
void	ft_which_box_in(t_game *game);
void	ft_delta_dist(t_game *game);
void	ft_side_dist(t_game *game);
void	ft_dda(t_game *game, char c);
void	ft_wall_height(t_game *game, int scale, char c);

/*UNTEXTURE CALCULATIONS*/
void	ft_raycasting_untextured(t_game *game);

/*TEXTURES CALCULATION*/
void	ft_wall_x(t_game *game);
void	ft_tex_x(t_game *game, int scale);
int		ft_chose_color(t_game *game);

/*DRAWING*/
void	ft_set_wall_texture(t_game *game);
void	update_image_from_buffer(t_game *game, t_position *data,
			int **buffer);
void	buffering_image_stripe(t_game *game, int **buffer, int x, int y);
void	ft_drawing_enemys_and_weapon(t_game *game, int **pixels_buffer);
void	draw_crosshair(t_game *game);

/*ABOUT WEAPON*/
void	ini_weapon(t_game *game);
void	draw_weapon(t_game *game, int **buffer, int weapon_type);
void	check_mouse_hooks(t_game *game);

/*ABOUT ENEMY*/
void	ft_enemy_height(t_game *game);
void	ft_finding_enemys_and_doors(t_game *game, int x, int **buffer);
int		find_enemy_ray(t_game *game);
void	enemy_can_die(t_game *game, int **buffer);
void	draw_enemy(t_game *game, int **buffer);

/*ABOUT DOORS*/
void	ft_finding_doors(t_game *game, int **buffer, int x);

/*LOAD TEXTURES*/
void	load_texture(t_game *game, char *relative_path, int index);
void	load_all_textures(t_game *game);

/*RAYCASTING*/
void	ft_raycasting(t_game *game);

/*UTILS*/
int		min(int a, int b);
int		max(int a, int b);
void	display_big_cub3d(void);
void	display_controls(void);
void	init_connection(t_game *game);

/*MINIMAP*/
void	draw_minimap(t_game *game);

#endif