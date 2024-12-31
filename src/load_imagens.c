/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imagens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:57:40 by asofia-g          #+#    #+#             */
/*   Updated: 2024/12/30 00:59:21 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	load_img(t_game *game, char *relative_path, int i)
{
	var->imgs[i].relative_path = relative_path;
	var->imgs[i].img = mlx_xpm_file_to_image(
        var->mlx, relative_path,
			&var->imgs[i].img_width, &var->imgs[i].img_height);
}