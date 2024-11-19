/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:21:03 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/20 17:46:58 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;

	i = -1;
	string = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (s[++i] != '\0')
		string[i] = (*f)(i, s[i]);
	string[i] = '\0';
	return (string);
}

//test
/*
char    aux(unsigned int i, char c)
{
	(void)i;
	c = 'Z';
	return (c);
}
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("string criada = %s", ft_strmapi(argv[1], &aux));
}
*/
