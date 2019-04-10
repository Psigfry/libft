/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:38:50 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/04 15:56:31 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *find)
{
	unsigned int a;
	unsigned int i;

	if (!*find)
		return ((char*)str);
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == find[0])
		{
			i = 1;
			while (find[i] != '\0' && str[a + i] == find[i])
				++i;
			if (find[i] == '\0')
				return ((char*)&str[a]);
		}
		++a;
	}
	return (0);
}
