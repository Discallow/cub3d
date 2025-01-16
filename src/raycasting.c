/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:27:37 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/16 06:46:39 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_get_player_inicial_direction(t_game *game)
{
	static int	flag = 0;
	if (flag)
		return;
	if (game->player.dir == 'N')
		game->player.dir_y = -1.0;
	if (game->player.dir == 'S')
		game->player.dir_y = 1.0;
	if (game->player.dir == 'E')
		game->player.dir_x = 1.0;
	if (game->player.dir == 'W')
		game->player.dir_x = -1.0;
	game->player.angle = atan2(game->player.dir_y, game->player.dir_x);
	flag++;
}

/*calculate ray position and direction 
*camera plane is perpendicular to the direction
*Since the viewing angle of Wolfenstein 3D, the motif of cub3d, is 66°, 
*the value of the plane vector is set at ±0.66
*/
void	ft_ray_position(t_game *game, int x)
{
	game->calc.plane_x = - game->player.dir_y * 0.66;
	game->calc.plane_y = game->player.dir_x * 0.66;
	game->calc.camera_x = 2 * x / (double)game->x - 1;
	game->calc.last_ray_dir_x = game->calc.ray_dir_x;
	game->calc.last_ray_dir_y = game->calc.ray_dir_y;
	game->calc.ray_dir_x = game->player.dir_x + 
						game->calc.plane_x * game->calc.camera_x;
	game->calc.ray_dir_y = game->player.dir_y + 
						game->calc.plane_y * game->calc.camera_x;
	//printf("dir_x=%f, dir_y= %f, plane_x=%f, plane_y=%f, camera_x=%f, ray_dir_x=%f, ray_dir_y=%f\n", game->player.dir_x, game->player.dir_y, game->calc.plane_x, game->calc.plane_y, game->calc.camera_x, game->calc.ray_dir_x, game->calc.ray_dir_y);//APAGAR
}

/*which box of the map we're in*/
void	ft_which_box_in(t_game *game)
{
	// printf("player_x=%f, player_y=%f\n", game->player.x, game->player.y);//APAGAR
	// printf("player_angle=%f\n", game->player.angle);//APAGAR
	game->calc.map_x = (int)game->player.x;
	game->calc.map_y = (int)game->player.y;
}

/*length of ray from one x or y-side to next x or y-side*/
void	ft_delta_dist(t_game *game)
{
	if (game->calc.ray_dir_x == 0)
		game->calc.delta_dist_x = 1e30;
	else
		game->calc.delta_dist_x = fabs(1 / game->calc.ray_dir_x);
	if (game->calc.ray_dir_y == 0)
		game->calc.delta_dist_y = 1e30;
	else
		game->calc.delta_dist_y = fabs(1 / game->calc.ray_dir_y);
	//printf("delta_dist_x =%f, delta_dist_y =%f\n", game->calc.delta_dist_x, game->calc.delta_dist_y);//APAGAR
}

/*side_dist is length of ray from current position to next x or y-side
*step means what direction to step in x or y - direction (either +1 or -1)*/
void	ft_side_dist(t_game *game)
{
	if (game->calc.ray_dir_x < 0)
	{
		game->calc.step_x = -1;
		game->calc.side_dist_x = (game->player.x - 
								game->calc.map_x) * game->calc.delta_dist_x;
	}
	else
	{
		game->calc.step_x = 1;
		game->calc.side_dist_x = (game->calc.map_x + 1.0 - 
								game->player.x) * game->calc.delta_dist_x;
	}
	if (game->calc.ray_dir_y < 0)
	{
		game->calc.step_y = -1;
		game->calc.side_dist_y = (game->player.y - 
								game->calc.map_y) * game->calc.delta_dist_y;
	}
	else
	{
		game->calc.step_y = 1;
		game->calc.side_dist_y = (game->calc.map_y + 1.0 - 
								game->player.y) * game->calc.delta_dist_y;
	}
	//printf("x:%f, y:%f\n", game->calc.side_dist_x, game->calc.side_dist_y);
	//printf("x:%f, y:%f\n", game->player.x, game->player.y);
	//draw_line(&game->map2, (int)game->player.x, (int)game->player.y, (int)(game->calc.side_dist_x) / SCALE, (int)(game->calc.side_dist_y) / SCALE, 0x00FF0000);
	// printf("side_dist_x=%f, side_dist_y=%f\n", game->calc.side_dist_x, game->calc.side_dist_y);//APAGAR
}

/*jump to next map square, either in x-direction, or in y-direction
*if we hit a wall we break out of the loop
*wall_side = 0, means we hit vertical side of the wall
*wall_side = 1, means we hit horizontal side of the wall*/
void	ft_dda(t_game *game, char c)
{
	// printf("ANTES:side_dist_x =%f, side_dist_y =%f, map x,y = %c\n",game->calc.side_dist_x, game->calc.side_dist_y, game->map[game->calc.map_y][game->calc.map_x]);//APAGAR
	while (1)
	{
		if (game->calc.side_dist_x < game->calc.side_dist_y)
		{
			game->calc.side_dist_x += game->calc.delta_dist_x;
			game->calc.map_x += game->calc.step_x;
			game->calc.wall_side = VERTICAL;
		}
		else
		{
			game->calc.side_dist_y += game->calc.delta_dist_y;
			game->calc.map_y += game->calc.step_y;
			game->calc.wall_side = HORIZONTAL;
		}
		// printf("map_x=%d, map_y=%d\n", game->calc.map_x, game->calc.map_y);//APAGAR
		//printf("map[map_x][map_y]=%d\n", game->map[game->calc.map_x][game->calc.map_y]);//APAGAR
		if (game->map[game->calc.map_y][game->calc.map_x] == 'X')
			game->calc.enemy_in = 1;
		if (game->map[game->calc.map_y][game->calc.map_x] == 'P' && c == 'P')
		{
/* 			printf("aqui2\n"); */
			game->door.flag = true;
			break ;
		}
		if (game->map[game->calc.map_y][game->calc.map_x] == '1' ||
				game->map[game->calc.map_y][game->calc.map_x] == c) 
			break;
	}
	// printf("DEPOIS:side_dist_x =%f, side_dist_y =%f, map x,y = %c\n",game->calc.side_dist_x, game->calc.side_dist_y, game->map[game->calc.map_y][game->calc.map_x]);//APAGAR
}

/*Calculate distance of perpendicular ray, i.e. remove fisheye effect!*/
void	ft_wall_height(t_game *game, int scale, char c)
{
	if (game->calc.wall_side == VERTICAL)
	{
		game->calc.wall_dist = (game->calc.map_x - game->player.x +
			(1 - game->calc.step_x) / 2) / game->calc.ray_dir_x;
	}
	else
			game->calc.wall_dist = (game->calc.map_y - game->player.y + 
				(1 - game->calc.step_y) / 2) / game->calc.ray_dir_y;
	if (c == 'X')
		game->enemy.wall_dist = game->calc.wall_dist;
	if (c == 'P')
		game->door.wall_dist = game->calc.wall_dist;
	game->calc.line_height = fmax((int)(game->y / 
								(scale * game->calc.wall_dist)), 0);
	game->calc.draw_start = -game->calc.line_height / 2 + game->y / 2;
	if (game->calc.draw_start < 0)
		game->calc.draw_start = 0;
	game->calc.draw_end = game->calc.line_height / 2 + game->y / 2;
	if (game->calc.draw_end >= game->y || game->calc.wall_dist < 0.01)
		game->calc.draw_end = game->y - 1;
}

void	ft_enemy_height(t_game *game)
{
	double	enemy_dist;
	
	// Calcula a distância euclidiana entre o jogador e o inimigo
	double dx = game->enemy.x - game->player.x;
	double dy = game->enemy.y - game->player.y;
	enemy_dist = sqrt(dx * dx + dy * dy);

	// Calcula a altura do inimigo com base na distância
	if (enemy_dist > 0.0)
		game->calc.enemy_height = (int)(game->y / enemy_dist);
	else
		game->calc.enemy_height = game->y;
	ft_wall_height(game, 1, 'X');
	// Debug para verificar os valores
	//printf("enemy_dist = %f\n", enemy_dist);
	//printf("enemy_height = %d\n", game->calc.enemy_height);
}

/*Calculate value of wallX, where exactly the wall was hit*/
void	ft_wall_x(t_game *game)
{	
	if (game->calc.wall_side == VERTICAL)
	{
		game->calc.wall_x = game->player.y + 
								game->calc.wall_dist * game->calc.ray_dir_y;
	}
	else
	{
		game->calc.wall_x = game->player.x + 
								game->calc.wall_dist * game->calc.ray_dir_x;
	}
	game->calc.wall_x -= floor(game->calc.wall_x);
	//printf("game->calc.wall_x:%f\n", game->calc.wall_x);
}

/*Calculate x coordinate on the texture*/
void	ft_tex_x(t_game *game, int scale)
{
	ft_set_wall_texture(game);
	game->calc.tex_x = (int)(game->calc.wall_x * 
			game->tex_buff_data[game->calc.tex_drawn].tex_width * scale);

	if ((game->calc.wall_side == VERTICAL && game->calc.ray_dir_x < 0) ||
		(game->calc.wall_side == HORIZONTAL && game->calc.ray_dir_y > 0))
	game->calc.tex_x = game->tex_buff_data[game->calc.tex_drawn].tex_width
						 - game->calc.tex_x - 1;		
}

/*give x and y sides different brightness*/
int	ft_chose_color(t_game *game)
{
	int color;

	color = 0x000000FF;
	if (game->calc.wall_side == VERTICAL) 
		color = ((color >> 1) & 0x7F7F7F);
	return(color);
}
/*y-coordinate first because it works per collums*/
int		**init_pixels_buffer(t_game *game)
{
	int **pixels_buffer;
	int	i;

	pixels_buffer = ft_calloc(game->y + 1, sizeof * pixels_buffer);
	// if (!pixels_buffer)//MALLOC ERROR MSG + Clean everithing
	i = 0;
	while (i < game->y) 
	{
		pixels_buffer[i] = ft_calloc(game->x + 1, sizeof pixels_buffer);
		// if (!pixels_buffer[i])//MALLOC ERROR MSG + Clean everithing
		i++;
	}
	return(pixels_buffer);
}

/*UNTEXTURED VERTION*/
void	ft_raycasting_untextured(t_game *game)
{
	int	x;
	int color;//for untextured

	x = 0;
	ft_get_player_inicial_direction(game);
	while (x < game->x)
	{
		ft_ray_position(game, x);
		ft_which_box_in(game);
		ft_delta_dist(game);
		ft_side_dist(game);
		ft_dda(game, '1');
		ft_wall_height(game, 1, '1');
		color = ft_chose_color(game);//for untextured
		//printf("game.->map2=%p\n", &game->map2);//APAGAR
		//printf("x:%d, game->calc.draw_start:%d, game->calc.draw_end:%d\n", x, game->calc.draw_start, game->calc.draw_end);
		ver_Line(&game->map2, x, game->calc.draw_start, game->calc.draw_end, color);//for untextured
		x++;
	}
}
/*Check if the vector player-enemy is aligned with the ray*/
int find_enemy_ray(t_game *game)
{
	double	ray_dir_x_current;
	double	ray_dir_y_current;
	double	ray_dir_x_next;
	double	ray_dir_y_next;

	ray_dir_x_current = game->calc.last_ray_dir_x;
	ray_dir_y_current = game->calc.last_ray_dir_y;
	ray_dir_x_next = game->calc.ray_dir_x;
	ray_dir_y_next = game->calc.ray_dir_y;
	// Vetor entre jogador e inimigo
	double player_to_enemy_x = game->enemy.x - game->player.x;
	double player_to_enemy_y = game->enemy.y - game->player.y;

	// Produto vetorial do raio atual
	double cross_product_current = (ray_dir_x_current * player_to_enemy_y) - 
								   (ray_dir_y_current * player_to_enemy_x);

	// Produto vetorial do próximo raio
	double cross_product_next = (ray_dir_x_next * player_to_enemy_y) - 
								(ray_dir_y_next * player_to_enemy_x);

	// Verifica mudança de sinal no produto vetorial
	if (cross_product_current * cross_product_next < 0)
		return 1; // Passou pelo vetor jogador-inimigo
	return 0; // Não passou ainda
}

void	enemy_can_die(t_game *game, int **buffer)
{
	double	dist;

	dist = sqrt(pow(game->enemy.x - game->player.x, 2) + 
				pow(game->enemy.y - game->player.y, 2));
	if (game->calc.enemy_height && game->player.shoot)
	{
		// printf("enemy_pos=%d, game->x / 2 =%d, dist = %f\n", game->calc.enemy_pos, game->x / 2, dist);//APAGAR
		if (game->calc.enemy_pos > game->x / 2 - ((game->y / WEAPON_SCALE)) 
			&& game->calc.enemy_pos < game->x / 2 + ((game->y / WEAPON_SCALE))
			&& dist < 2.0 && (game->player.flag || !game->door.open_door 
								|| game->enemy.wall_dist < game->door.wall_dist))
			{
				// draw_enemy(game, buffer);//necessário fazer como na weapon para mudar a imagem
				printf("inimigo morreu");//APAGAR
				game->map[(int)game->enemy.y][(int)game->enemy.x] = '0';
			}
	}
	else if (game->calc.enemy_height 
					&& (game->player.flag || !game->door.open_door 
							|| game->enemy.wall_dist < game->door.wall_dist))
		draw_enemy(game, buffer);
}

void	ft_finding_doors(t_game *game, int **buffer, int x)
{
		ft_which_box_in(game);
		ft_side_dist(game);
		ft_dda(game, 'P');
	if (game->door.flag)
	{
/* 		printf("aqui\n"); */
		ft_wall_height(game, 1,'P');
		ft_wall_x(game);//just for textures
		ft_tex_x(game, 1);//just for textures
		buffering_image_stripe(game, buffer, x);//just for textures
	}
	
}

/*TEXTURED VERTION*/
void	ft_raycasting(t_game *game)
{
	int	x;
	int **pixels_buffer; //just for textures
	
	pixels_buffer = init_pixels_buffer(game);//just for textures
	x = 0;
	ft_get_player_inicial_direction(game);
	game->calc.enemy_height = 0;
	while (x < game->x)
	{
		game->calc.enemy_in = 0;
		ft_ray_position(game, x);
		ft_which_box_in(game);
		ft_delta_dist(game);
		ft_side_dist(game);
		ft_dda(game, '1');
		ft_wall_height(game, 1, '1');
		ft_wall_x(game);//just for textures
		ft_tex_x(game, 1);//just for textures
		buffering_image_stripe(game, pixels_buffer, x);//just for textures

		/*FINDING ENEMYS*/
		ft_which_box_in(game);
		ft_side_dist(game);
		ft_dda(game, 'X');
		if (game->calc.enemy_in == 1 && game->calc.enemy_height == 0 
										&& find_enemy_ray(game))
		{
			// game->calc.enemy_height = game->calc.line_height;
			ft_enemy_height(game);
			game->calc.enemy_pos = x;
			// printf("x = %d\n", x);//APAGAR
			// ft_wall_height(game, 5);
			// ft_wall_x(game);//just for textures
			// ft_tex_x(game, 5);//just for textures
			// buffering_image_stripe(game, pixels_buffer, x, 1);//just for textures		
		}
		ft_finding_doors(game, pixels_buffer, x);
		x++;
	}
	//printf("enemy.height = %d\n", game->calc.enemy_height);//APAGAR
	if (game->calc.enemy_height && (game->player.flag || !game->door.open_door
			|| game->enemy.wall_dist < game->door.wall_dist))
		draw_enemy(game, pixels_buffer);
	// printf("open_door=%d, player_flag = %d, door.flag = %d\n", game->door.open_door, game->player.flag, game->door.flag);//APAGAR
	enemy_can_die(game, pixels_buffer);
	if (game->player.shoot)
		draw_weapon(game, pixels_buffer, WEAPON_SHOOTING);
	else
		draw_weapon(game, pixels_buffer, WEAPON);
		
	
	update_image_from_buffer(game,&game->map2,pixels_buffer);//just for textures
	free_pixels_buffer(pixels_buffer, game->y);//just for textures
}

