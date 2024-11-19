/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-c <asofia-c@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:01:44 by asofia-c          #+#    #+#             */
/*   Updated: 2023/10/02 14:44:13 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
//test
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com isdigit: %d\n", isdigit(argv[1][0]));
	printf("Resultado com ft_isdigit: %d\n", ft_isdigit(argv[1][0]));
}
//end test*/
