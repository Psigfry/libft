/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:40:35 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/10 13:16:36 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	if (!(s1 && s2))
		return (0);
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = (char)s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = (char)s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
