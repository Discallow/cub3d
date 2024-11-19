/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:59:49 by dioalexa          #+#    #+#             */
/*   Updated: 2024/10/01 15:40:48 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n && str1[i] == str2[i])
		i++;
	if (n == 0 || i == n)
		return (0);
	return ((int)(unsigned char )str1[i] - (int)(unsigned char )str2[i]);
}
/*int main()
{
	const char *s1 = "Hello, World!";
	const char *s2 = "Hello, Worla!";
	int result = ft_strncmp(s1, s2, 13);
	printf("Comparison result: %d\n", result);

	return 0;
}*/
