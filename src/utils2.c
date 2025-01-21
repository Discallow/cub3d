/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 07:47:52 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:29:06 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	display_big_cub3d(void)
{
	printf(CYAN BOLD "===============================================\n" RESET);
	printf("\n\n");
	printf(GREEN BOLD "   ██████╗║██╗   ██╗║██████╗ ██████╗   █████╗\n" RESET);
	printf(CYAN BOLD "  ██╔════╝║██║   ██║║██╔══██╗ ╚════██╗ ██╔══██╗\n" RESET);
	printf(YELLOW "  ██║     ║██║   ██║║██████╔╝  █████╔╝ ██║  ██║\n" RESET);
	printf(MAGENTA BOLD "  ██║     ║██║   ██║║██╔══██╗  ╚═══██╗ ██║" RESET);
	printf(MAGENTA BOLD "  ██║\n" RESET);
	printf(RED BOLD "  ╚██████ ║████████║║██████╔╝ ██████╔╝ ██████╔╝ \n" RESET);
	printf(BLUE BOLD "   ╚════╝ ╚════════╝╚══════╝  ╚═════╝  ╚═════╝\n" RESET);
	printf("\n");
}

void	display_controls(void)
{
	printf(CYAN BOLD "===============================================\n" RESET);
	printf(YELLOW BOLD "                        Controls\n" RESET);
	printf(MAGENTA "-----------------------------------------------\n" RESET);
	printf(GREEN BOLD "  Movement:\n" RESET);
	printf("    " CYAN "W or UP" RESET " - Move forward\n");
	printf("    " CYAN "S or DOWN" RESET " - Move backward\n");
	printf("    " CYAN "A" RESET " - Move left\n");
	printf("    " CYAN "D" RESET " - Move right\n\n");
	printf(GREEN BOLD "  Camera:\n" RESET);
	printf("    " CYAN "Left Arrow or Mouse" RESET "  - Rotate view left\n");
	printf("    " CYAN "Right Arrow or Mouse" RESET " - Rotate view right\n\n");
	printf(GREEN BOLD "  Actions:\n" RESET);
	printf("    " CYAN "Mouse1" RESET "  - Shoot\n");
	printf("    " RED "ESC" RESET " - Exit the game\n\n");
	printf(MAGENTA "------------------------------------------------\n" RESET);
	printf(BLUE BOLD "       Enjoy exploring the 3D world of Cub3D!\n" RESET);
	printf(CYAN BOLD "==============================================" RESET);
	printf("\n\n");
}

void	init_connection(t_game *game)
{
	game->connection = mlx_init();
	if (!game->connection)
	{
		printf(RED "Error:Couldn't start connection." RESET "\n");
		free_everything(game);
		exit(1);
	}
	mlx_get_screen_size(game->connection, &game->x, &game->y);
	game->window = mlx_new_window(game->connection, (game->x),
			(game->y), "CUB3D");
	if (!game->window)
	{
		printf(RED "Error:Couldn't open window." RESET "\n");
		mlx_destroy_window(game->connection, game->window);
		free_everything(game);
		exit(1);
	}
}
