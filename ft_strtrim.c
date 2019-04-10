/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:01:28 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/10 13:20:31 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*n;
	size_t	s2;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	s2 = ft_strlen(s);
	s2 -= s2 ? 1 : 0;
	while (s[s2] == ' ' || s[s2] == '\n' || s[s2] == '\t')
		s2--;
	s2++;
	if (!(n = ft_strnew(s2)))
		return (NULL);
	ft_strncpy(n, s, s2);
	return (n);
}
