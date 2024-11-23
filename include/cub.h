/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:40 by discallow         #+#    #+#             */
/*   Updated: 2024/11/23 03:47:06 by discallow        ###   ########.fr       */
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

# define RESET	"\033[0m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define CYAN	"\033[0;36m"

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
	int		red;
	int		green;
	int		blue;
	int		total;
	void	*img;
	char	*path;
}		t_position;

typedef struct	s_map_copy
{
	char	**map;
	int		exit;
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
	bool		elements_filled;
}				t_game;

char	*get_next_line(int fd);

/*PARSING*/
void	check_map(t_game *game, char *map);

#endif