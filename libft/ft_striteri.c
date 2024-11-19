/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:19:02 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/21 18:12:23 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
		(*f)(i, &s[i]);
}
//RECORDAR: funcoes void sao corridas para executarem alguma coisa, depois
//usamos o que elas "criacarm"
//test
/*
void	aux(unsigned int i, char *c)
{
	(void)i;
	*c = 'Z';
}
int	main(int argc, char *argv[])
{
	(void)argc;
	ft_striteri(argv[1],aux);
	printf ("new string = %s", argv[1]);
}
*/
//end test
