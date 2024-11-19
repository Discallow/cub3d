/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:53:27 by discallow         #+#    #+#             */
/*   Updated: 2024/07/11 04:53:44 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (i);
	while ((str1[i] || str2[i]) && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
