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

int	trim_last_line(char *last_read)
{
	ssize_t	nl_i;
	size_t	i;

	if (last_read[0] == 0)
	{
		ft_bzero(last_read, BUFFER_SIZE + 1);
		return (1);
	}
	nl_i = ft_i_strchr(last_read, '\n');
	if (nl_i == -1)
		return (0);
	i = 0;
	while (last_read[nl_i + i] != 0)
	{
		last_read[i] = last_read[nl_i + i];
		i++;
	}
	last_read[i] = 0;
	return (1);
}

// static char	*handle_shortline(char **current_buf_ptr)
// {
// 	if (ft_strlen(*current_buf_ptr) == 0)
// 	{
// 		free(*current_buf_ptr);
// 		*current_buf_ptr = 0;
// 		return (0);
// 	}
// 	return (ft_strldup(*current_buf_ptr, ft_strlen(*current_buf_ptr)));
// }

char	*get_next_line(int fd)
{
	static char	last_read[BUFFER_SIZE + 1];
	ssize_t		last_size;
	char		*current_buf;

	if (trim_last_line(last_read) == 0)
		return (0);
	current_buf = ft_strldup(last_read, ft_strlen(last_read));
	
	last_size = read(fd, last_read, BUFFER_SIZE);
	if (last_size == -1)
		return (0);

	// last_size = BUFFER_SIZE;
	// while (last_size == BUFFER_SIZE)
	// {
	// 	ft_bzero(last_read, BUFFER_SIZE + 1);
	// 	last_size = read(fd, last_read, BUFFER_SIZE);
	// 	if (last_size == -1)
	// 		return (0);
	// 	current_buf = ft_stradd(current_buf, last_read);
	// 	if (current_buf == 0)
	// 		return (0);
	// 	if (ft_i_strchr(current_buf, '\n') != -1)
	// 		return (ft_strldup(current_buf, ft_i_strchr(current_buf, '\n')));
	// }
	// return (handle_shortline(&current_buf));
	
	return (ft_strldup(current_buf, ft_i_strchr(current_buf, '\n')));
}
