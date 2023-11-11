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

// void	print_line(char *str)
// {
// 	if (str == 0)
// 	{
// 		write(1, "(null)", 6);
// 	}
// 	while (*str != 0)
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// 	write(1, "\n\n", 2);
// }

void	test_easy(int fd)
{
	char	*read_line;
	int	i;

	i = 5;
	while (i > 0)
	{
		read_line = get_next_line(fd);
		printf("read str = %s\n", read_line);
		free(read_line);
		i--;
	}
}

int	main(void)
{
	int		fd;

	fd = open("./test_files/ez.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file\n");
		return (1);
	}

	printf("\n");
	test_easy(fd);
	printf("\n");

	close(fd);
}