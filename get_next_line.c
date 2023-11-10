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

char	*get_next_line(int fd)
{
	static char*	last_read;
	static size_t	last_index;
	ssize_t			last_size;

	char*			current_buf;
	size_t			current_size;

	ssize_t	nl_index;
	nl_index = -1;
	last_size = BUFFER_SIZE;

	if (last_read == 0)
	{
		last_read = malloc(BUFFER_SIZE);
		current_buf = 0;
		current_size = 0;
	}
	else
	{
		current_buf = dup_buf(last_read, last_index, BUFFER_SIZE);
		current_size = BUFFER_SIZE - last_index;
	}

	while (nl_index == -1 && last_size == BUFFER_SIZE)
	{
		last_size = read(fd, last_read, BUFFER_SIZE);
		if (last_size == -1)
			return (0);
		current_buf = add_buf(current_buf, last_read, current_size, BUFFER_SIZE);
		current_size += last_size;

		nl_index = get_nl_index(current_buf, current_size, last_index);
	}
	
	last_index = nl_index + 1 - current_size + BUFFER_SIZE;

	if (last_size == BUFFER_SIZE)
		return (dup_buf(current_buf, 0, nl_index - 1));
	else
		return (dup_buf(current_buf, 0, current_size));
}
