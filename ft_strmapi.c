/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:16:52 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/09 17:00:38 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = -1;
	if (!s || !(str = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	while (s[++i])
	{
		str[i] = f(i, s[i]);
	}
	return (str);
}
