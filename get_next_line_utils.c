/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:55:55 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/10 15:38:09 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	get_nl_index(char *s, size_t size, size_t i)
{
	while (i < size)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*dup_buf(char *s, size_t start, size_t end)
{
	char	*dup;
	size_t	i;

	dup = malloc(end + 1 - start);
	if (dup == 0)
		return (0);
	i = start;
	while (i < end)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*add_buf(char *s1, char *s2, size_t size1, size_t size2)
{
	size_t	i;
	size_t	j;
	char	*new;

	new = malloc(size1 + size2);
	i = 0;
	while(i < size1)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while(j < size2)
	{
		new[i + j] = s2[j];
		j++;
	}
	return (new);
}