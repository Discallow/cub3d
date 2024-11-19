/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:05:58 by asofia-g          #+#    #+#             */
/*   Updated: 2024/09/05 19:41:50 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*buffer;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	buffer = (char *)malloc((total_len + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	ft_strlcat(buffer, s2, total_len + 1);
	return (buffer);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("%s",ft_strjoin(argv[1], argv[2]));
}
*/
//end test
