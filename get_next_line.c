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

static void	trim_last_line(char *last_read)
{
	ssize_t	nl_i;
	size_t	i;

	nl_i = ft_i_strchr(last_read, '\n');
	if (nl_i == -1)
	{
		ft_bzero(last_read, BUFFER_SIZE + 1);
		return ;
	}
	i = 0;
	while (last_read[nl_i + 1 + i] != 0)
	{
		last_read[i] = last_read[nl_i + 1 + i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		last_read[i] = 0;
		i++;
	}
}

static char	*handle_return(char *current_buf, char return_on, char *last_read)
{
	char	*temp;

	if (ft_strlen(current_buf) == 0)
	{
		free(current_buf);
		return (0);
	}
	if (return_on != 0)
		temp = ft_strldup(current_buf, ft_i_strchr(current_buf, return_on) + 1);
	else
		temp = ft_strldup(current_buf, ft_strlen(current_buf));
	free(current_buf);
	trim_last_line(last_read);
	if (temp == 0)
		return (0);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	last_read[BUFFER_SIZE + 1];
	ssize_t		last_size;
	char		*current_buf;

	current_buf = ft_strldup(last_read, ft_strlen(last_read));
	if (current_buf == 0)
		return (0);
	last_size = BUFFER_SIZE;
	while (ft_i_strchr(last_read, '\n') == -1)
	{
		if (last_size != BUFFER_SIZE)
			return (handle_return(current_buf, 0, last_read));
		ft_bzero(last_read, BUFFER_SIZE + 1);
		last_size = read(fd, last_read, BUFFER_SIZE);
		if (last_size == -1)
		{
			free(current_buf);
			return (0);
		}
		current_buf = ft_stradd(current_buf, last_read);
		if (current_buf == 0)
			return (0);
	}
	return (handle_return(current_buf, '\n', last_read));
}
