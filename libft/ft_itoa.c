/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:20:16 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/17 20:20:44 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ascii;
	int		rest;
	int		i;

	i = ((n == 0) || (n < 0));
	rest = n;
	while (rest != 0)
	{
		rest = rest / 10;
		i++;
	}
	ascii = (char *)malloc((i + 1) * sizeof(char));
	if (ascii == NULL)
		return (NULL);
	ascii[i] = '\0';
	rest = n;
	while (--i >= 0 && !(n < 0 && i == 0))
	{
		ascii[i] = ((rest % 10) * ((rest > 0) - (rest < 0)) + '0');
		rest = rest / 10;
	}
	if (n < 0 && i == 0)
		ascii[0] = '-';
	return (ascii);
}
//test
//EXPLICACAO (rest > 0) - (rest < 0) troca o sinal para controlar os negativos
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("string: %s", ft_itoa(ft_atoi(argv[1])));

}
*/
//end test
