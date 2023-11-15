/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:06:06 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/14 14:06:06 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	ft_bzero(char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		s[i] = 0;
		i++;
	}
}

ssize_t	ft_i_strchr(const char *s, int c)
{
	char	cc;
	size_t	i;

	cc = (char) c;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == cc)
			return (i);
		i++;
	}
	if (cc == 0)
		return (i);
	return (-1);
}

char	*ft_strldup(const char *s1, size_t len)
{
	char	*dup;
	size_t	i;

	dup = malloc(len + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_stradd(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new != 0)
	{
		i = 0;
		while (s1[i] != 0)
		{
			new[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != 0)
		{
			new[i + j] = s2[j];
			j++;
		}
		new[i + j] = 0;
	}
	free(s1);
	return (new);
}
