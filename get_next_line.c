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
	static char*	str_read;
	static ssize_t	start_index;

	char*			total_read;
	ssize_t			total_size;
	
	total_read = str_read;
	total_size = 0;
	while(get_nl_index(total_read, total_size, start_index) == 0)
	{
		str_read = malloc(BUFFER_SIZE);
		if (read(fd, str_read, BUFFER_SIZE) < BUFFER_SIZE)
			return (0);
		total_read = memjoin(total_read, str_read, total_size, BUFFER_SIZE);
		total_size += BUFFER_SIZE;

		printf("total_read = %s\ntotal_size = %zd\nstart_index = %zd\n\n", total_read, total_size, start_index);
	}
	return (memdup(total_read, start_index, get_nl_index(total_read, total_size, start_index)));
}
