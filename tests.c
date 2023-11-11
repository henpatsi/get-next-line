/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:40:31 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/10 15:46:47 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "get_next_line.h"

void	print_line(char *str)
{
	if (str == 0)
	{
		write(1, "(null)", 6);
	}
	while (*str != '\n' && *str != 0)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 2);
}

void	test_file(char *file)
{
	char	*read_line;
	int		fd;

	printf("\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file: \"%s\"\n", file);
		return ;
	}
	read_line = get_next_line(fd);
	while (read_line != 0)
	{
		print_line(read_line);
		free(read_line);
		read_line = get_next_line(fd);
	}
	free(read_line);
	close(fd);
	printf("\n");
}

int	main(void)
{
	test_file("./test_files/ez.txt");
	test_file("./test_files/longline.txt");
}