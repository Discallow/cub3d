/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:40 by discallow         #+#    #+#             */
/*   Updated: 2024/12/03 12:14:25 by discallow        ###   ########.fr       */
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

# define RESET		"\033[0m"
# define BOLD    	"\033[1m"
# define UNDERLINE 	"\033[4m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"

# define NEWLINE 1

typedef enum	e_element
{
	CEILING,
	FLOOR,
}				t_element;

typedef struct s_position
{
	int		x;
	int		y;
	int		num;
	char	**rgb;
	int		color;
	int		total;
	void	*img;
	char	*path;
}		t_position;

typedef struct	s_map_copy
{
	int		exit;
	int		line_index;
	bool	elements_filled;
	bool	map_read;
	int		start_line;
	int		last_line;
	char	*map_joined;
	int		player_num;
	
}				t_map_copy;

typedef struct	s_game
{
	char	**map;
	t_position	north;
	t_position	south;
	t_position	west;
	t_position	east;
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

#endif