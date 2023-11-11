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

int	fd_out;

void	print_line(char *str)
{
	write(1, "line: ", 6);
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

void	write_to_file(char *str)
{
	while (*str != '\n' && *str != 0)
	{
		if (write(fd_out, str, 1) == -1)
		{
			printf("writing to output failed");
			return ;
		}
		str++;
	}
}

int	test_file(char *file, int lines)
{
	char	*read_line;
	int		fd;

	printf("\n");
	printf("testing file: \"%s\"\n\n", file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file\n");
	}
	else
	{
		read_line = get_next_line(fd);
		while (read_line != 0)
		{
			print_line(read_line);
			write_to_file(read_line);
			free(read_line);
			read_line = get_next_line(fd);
			lines--;
		}
		free(read_line);
		close(fd);
	}
	printf("\n");
	return (lines);
}

int	main(void)
{
	int	lines_left;

	fd_out = open("test_files/output.txt", O_WRONLY | O_APPEND | O_CREAT);
	if (fd_out == -1)
		printf("error opening output file\n");

	lines_left = test_file("./test_files/ez.txt", 5);
	printf("%d lines left unread\n", lines_left);
	lines_left = test_file("./test_files/letters.txt", 26);
	printf("%d lines left unread\n", lines_left);
	lines_left = test_file("./test_files/longline.txt", 3);
	printf("%d lines left unread\n", lines_left);
	lines_left = test_file("./test_files/notext.txt", 10);
	printf("%d lines left unread\n", lines_left);
	lines_left = test_file("./test_files/empty.txt", 1);
	printf("%d lines left unread\n", lines_left);

	close(fd_out);
}