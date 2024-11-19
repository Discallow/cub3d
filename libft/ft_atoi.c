/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:34:13 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/08 17:17:21 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	si;

	i = 0;
	result = 0;
	si = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		si = -1;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (si * result);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com atoi: %d\n", atoi(argv[1]));
	printf("Resultado com ft_atoi: %d\n", ft_atoi(argv[1]));
}
*/
//end test
