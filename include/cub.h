/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:40 by discallow         #+#    #+#             */
/*   Updated: 2024/12/31 10:09:13 by asofia-g         ###   ########.fr       */
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
# include <math.h>//math functions, need -lm to compile
# include <stdint.h>//to use uint32_t, int > 0 with 32 bits 
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
# define SCALE			5
# define texWidth 		64
# define texHeight 		64
# define NUM_TEXTURES 	4

typedef enum	e_element
{
	CEILING,
	FLOOR,
}				t_element;

typedef struct s_position
{
	double	x;
	double	y;
	float	size;
	int		num;
	char	*dir;
	double	dir_x;
	double	dir_y;
	int		flag_pos;
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
	double	move_speed;
	double	rotation_speed;
}		t_position;

typedef struct	s_map_copy
{
	double	x;
	double	y;
	int		exit;
	int		line_index;
	bool	elements_filled;
	bool	map_read;
	int		start_line;
	int		last_line;
	int		max_width;
	int		max_height;
	char	*map_joined;
	int		player_num;
	
}				t_map_copy;

typedef struct	s_calculation
{
	double	camera_x;
	int		ray;
	double	ray_angle;
	double	ray_dir_x;
	double	ray_dir_y;
	double	x_offset;
	double	y_offset;
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
	int 	draw_start;
	int 	draw_end;
	double	wall_x;
}				t_calculation;

typedef struct	s_game
{
	char	**map;
	t_position	north;
	t_position	south;
	t_position	west;
	t_position	east;
	int		x_len;
	int		y_len;
	int		x;
	int		y;
	int		fd;
	t_map_copy	copy;
	t_position	player;
	t_position	exit;
	t_position	wall;
	t_position	floor;
	t_position	ceiling;
	t_position	enemy;
	t_position	map2;
	void		*window;
	void		*connection;
	double		delta_x;
	double		delta_y;
	t_calculation	calc;
}				t_game;

char	*get_next_line(int fd);

/*PARSING*/
void	check_map(t_game *game, char *map);
void	return_invalid_color(char *str, t_game *game, char *line);
void	return_invalid_number_players(t_game *game);
void	return_invalid_map(t_game *game);
void	return_invalid_line(t_game *game, char *line);
void	skip_spaces(char *line, size_t *i);
int		ft_atoi2(const char *s);
char	*ft_strjoin3(char *s1, char *s2);
int		ft_strcmp2(char *str1);
void	check_extension(char *file);
void	open_file(t_game *game, char *file);
void	check_valid_element(char *line, t_game *game);
void	check_valid_color(t_game *game, char *line, int i);
bool	check_elements_filled(t_game *game);
void	check_valid_line(char *line, t_game *game);
void	check_rgb_value( t_game *game, t_position *element, char *line);
void	check_one_or_space(t_game *game, int i);
void	validate_map(t_game *game);
void	read_map(t_game *game);
void	read_file(t_game *game);
void	check_valid_map(char *line, t_game *game);
char	*check_name(t_game *game, char *line, char *complete_line);
void	check_map_end(t_game *game, char *line);
void	check_borders(t_game *game, int x, int y);
void	check_first_last_line(t_game *game);

/*CLEANING ROUTINE*/
void	free_everything(t_game *game);

/*MOVES*/
void	redraw_map(t_game *game);
void	build_map(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	rotate_right(t_game *game);
void	draw_square(t_position *data, int x, int y, int start_x, int start_y, int color);
void	my_mlx_pixel_put(t_position *data, int x, int y, int color);
void	build_map(t_game *game);
void	destroy_map(t_game *game);
void	rotate_left(t_game *game);

/*DRAWING*/
void	my_mlx_pixel_put(t_position *data, int x, int y, int color);
void    ver_Line(t_position *data, int pos_x, int start, int end, int color);
void	draw_line(t_position *data, int x0, int y0, int x1, int y1, int color);

/*RAYCASTING*/
void	ft_raycasting(t_game *game);

#endif