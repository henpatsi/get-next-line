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

static char	*initialize_buffer(void)
{
	char	*temp;

	temp = malloc(BUFFER_SIZE + 1);
	if (temp == 0)
		return (0);
	ft_bzero(temp, BUFFER_SIZE + 1);
	return (temp);
}

static char	*trim_buffer(char *current_buf)
{
	char	*temp;
	ssize_t	nl_i;

	if (current_buf == 0)
	{
		// printf("-buffer is 0-\n");
		return (initialize_buffer());
	}
	nl_i = ft_i_strchr(current_buf, '\n');
	if (nl_i == -1)
	{
		free(current_buf);
		return (0);
	}
	temp = ft_strldup(&current_buf[nl_i + 1], ft_strlen(current_buf) - nl_i);
	free(current_buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*current_buf;
	char			last_read;
	ssize_t			last_size;

	// printf("gnl\n");
	current_buf = trim_buffer(current_buf);
	if (current_buf == 0)
	{
		// printf("---buffer 0---\n");
		// fflush(stdout);
		return (0);
	}
	last_size = BUFFER_SIZE;
	while (last_size == BUFFER_SIZE)
	{
		last_read = malloc(BUFFER_SIZE + 1);
		if (last_read == 0)
			return (0);
		ft_bzero(last_read, BUFFER_SIZE + 1);
		last_size = read(fd, last_read, BUFFER_SIZE);
		if (last_size == -1)
			return (0);
		current_buf = ft_strcombine(current_buf, last_read);
		if (current_buf == 0)
			return (0);
		if (ft_i_strchr(current_buf, '\n') != -1)
			return (ft_strldup(current_buf, ft_i_strchr(current_buf, '\n')));
	}
	if (ft_strlen(current_buf) == 0)
	{
		free(current_buf);
		current_buf = 0;
		// printf("---buffer set to 0---\n");
		// fflush(stdout);
		return (0);
	}
	return (ft_strldup(current_buf, ft_strlen(current_buf)));
}
