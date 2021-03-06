/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:47:07 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/04 17:53:45 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s, const char *c, size_t z)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
		++i;
	while (c[j] && j < z)
		s[i++] = c[j++];
	s[i] = '\0';
	return ((char*)s);
}
