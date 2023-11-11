/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:31:40 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/10 15:49:27 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*cut_last_line(char *current_buf)
{
	char	*temp;
	ssize_t	nl_i;

	nl_i = ft_i_strchr(current_buf, '\n');
	temp = ft_strldup(&current_buf[nl_i + 1], ft_strlen(current_buf) - nl_i);
	free(current_buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*current_buf;
	char			*last_read;
	ssize_t			last_size;

	if (current_buf)
		current_buf = cut_last_line(current_buf);
	else
		current_buf = malloc(0);

	last_read = malloc(BUFFER_SIZE + 1);
	ft_bzero(last_read, BUFFER_SIZE + 1);
	if (last_read == 0)
		return 0;

	last_size = BUFFER_SIZE;
	while (1)
	{
		last_size = read(fd, last_read, BUFFER_SIZE);
		if (last_size == -1)
			return (0);
		current_buf = ft_stradd(current_buf, last_read);
		if (ft_i_strchr(current_buf, '\n') != -1)
			return (ft_strldup(current_buf, ft_i_strchr(current_buf, '\n')));
		if (last_size != BUFFER_SIZE)
			return (ft_strldup(current_buf, ft_strlen(current_buf)));
	}

	return (0);
}
