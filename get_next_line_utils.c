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

char	*memdup(char *org, ssize_t start, ssize_t end)
{
	char	*dup;
	ssize_t	i;

	if (org == 0)
		return (0);
	if (start >= end)
		return (0);
	dup = malloc(end + 1 - start + 1);
	if (dup == 0)
		return (0);
	i = start;
	while (i <= end)
	{
		dup[i] = org[i];
		i++;
	}
	return (dup);
}

char *memjoin(char *s1, char *s2, ssize_t size1, ssize_t size2)
{
	char	*new;
	ssize_t	i;
	ssize_t	j;

	new = malloc(size1 + size2 + 1);
	if (new == 0)
		return (0);
	i = 0;
	while (i < size1)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size1)
	{
		new[i + j] = s2[j];
		j++;
	}
	free(s2);
	return (new);
}

int	get_nl_index(char *s, ssize_t size, ssize_t i)
{
	while (i < size && s[i] != -1)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}