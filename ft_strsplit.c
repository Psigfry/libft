/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:53:47 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/10 14:26:49 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	nm_word(char const *s, char c)
{
	unsigned int is;
	unsigned int j;

	is = 0;
	j = 0;
	while (s[is] != '\0')
	{
		while (s[is] == c)
			is++;
		if (s[is] != c && s[is] != '\0')
			j++;
		while (s[is] != c && s[is] != '\0')
			is++;
	}
	return (j);
}

static unsigned int	ft_wordlen(char const *s, char c, unsigned int is)
{
	unsigned int len;

	len = 0;
	while (s[is] != c && s[is] != '\0')
	{
		len++;
		is++;
	}
	return (len);
}

static char			**ft_str(char **str, char *s, char c, unsigned int j)
{
	unsigned int i;
	unsigned int is;
	unsigned int k;

	is = 0;
	i = 0;
	while (i < j)
	{
		while (s[is] == c)
			is++;
		k = 0;
		if (!(str[i] = ft_strnew(ft_wordlen(s, c, is))))
			return (NULL);
		while (s[is] != c && s[is] != '\0')
			str[i][k++] = s[is++];
		str[i][k] = '\0';
		if (s[is] == '\0')
			return (str);
		i++;
	}
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	j;

	if (!s || !c)
		return (0);
	j = nm_word(s, c);
	if (!(str = (char **)ft_memalloc(sizeof(char *) * (j + 1))))
		return (NULL);
	return (ft_str(str, (char *)s, c, j));
}
