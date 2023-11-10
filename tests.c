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

int	main(void)
{
	int		fd;
	char	*read_str; 

	fd = open("./test_files/ez.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file\n");
		return (1);
	}

	read_str = get_next_line(fd);
	printf("\nread str = \"%s\"\n", read_str);

	read_str = get_next_line(fd);
	printf("\nread str = \"%s\"\n", read_str);

	read_str = get_next_line(fd);
	printf("\nread str = \"%s\"\n", read_str);

	read_str = get_next_line(fd);
	printf("\nread str = \"%s\"\n", read_str);

	read_str = get_next_line(fd);
	printf("\nread str = \"%s\"\n", read_str);

	close(fd);
}