/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:57:54 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/31 19:02:24 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
//test
/*
int     main(int argc, char *argv[])
{
	(void)argc;
	printf ("Resutado com tolower: %d\n", tolower(atoi(argv[1])));
	printf ("Resutado com ft_tolower: %d", ft_tolower(atoi(argv[1])));
}
*/
//test
