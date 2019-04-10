/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:06:36 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/10 14:31:31 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = -1;
	if (!s || !(str = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	else
		str = ft_strdup(s);
	while (s[++i])
		str[i] = f(s[i]);
	return (str);
}
