/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:57:30 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/04 16:03:31 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	unsigned int a;
	unsigned int i;

	if (!*find)
		return ((char*)str);
	a = 0;
	while (str[a] != '\0' && (size_t)a < len)
	{
		if (str[a] == find[0])
		{
			i = 1;
			while (find[i] != '\0' && str[a + i] == find[i] &&
					(size_t)(a + i) < len)
				++i;
			if (find[i] == '\0')
				return ((char*)&str[a]);
		}
		++a;
	}
	return (0);
}
