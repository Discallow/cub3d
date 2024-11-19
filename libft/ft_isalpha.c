/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-c <asofia-c@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:59:39 by asofia-c          #+#    #+#             */
/*   Updated: 2023/09/23 13:00:48 by asofia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com isalpha: %d\n", isalpha(argv[1][0]));
	printf("Resultado com ft_isalpha: %d", ft_isalpha(argv[1][0]));
}
//fim de teste
*/
