/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:34:13 by asofia-g          #+#    #+#             */
/*   Updated: 2024/03/06 16:53:27 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
*This atoil returns an integer limited to INT_MIN and INT_MAX, if it's out of
*the limits return INT_MIN -1 or INR_MAX +1 and prevent returning -1 out of
*limits
*/
long	ft_atoil(const char *nptr)
{
	long	result;
	int		i;
	long	si;

	i = 0;
	result = 0;
	si = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		si = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
		if (si * result > INT_MAX)
			return (si * result);
		if (si * result < INT_MIN)
			return (si * result);
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
