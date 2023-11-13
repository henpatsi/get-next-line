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

int	g_fd_out;

void	print_line(char *str)
{
	write(1, "line: ", 6);
	if (str == 0)
		write(1, "(null)", 7);
	else
	{
		while (*str != '\n' && *str != 0)
		{
			write(1, str, 1);
			str++;
		}
		if (*str == '\n')
			write(1, "(\\n)", 4);
		if (*str == 0)
			write(1, "(EOF)", 5);
	}
	write(1, "\n", 2);
}

// void	write_to_file(char *str)
// {
// 	while (*str != '\n' && *str != 0)
// 	{
// 		if (write(g_fd_out, str, 1) == -1)
// 		{
// 			printf("writing to output failed");
// 			return ;
// 		}
// 		str++;
// 	}
// }

int	read_whole_file(char *file, int lines)
{
	char	*read_line;
	int		fd;

	printf("\n");
	printf("testing file: \"%s\"\n\n", file);
	fd = open(file, O_RDONLY);
	fflush(stdout);
	if (fd == -1)
		printf("error opening file\n");
	else
	{
		while (1)
		{
			read_line = get_next_line(fd);
			if (read_line == 0)
				break ;
			lines--;
			print_line(read_line);
			//write_to_file(read_line);
			free(read_line);
		}
		free(read_line);
		close(fd);
	}
	printf("\n");
	printf("%d lines left unread\n", lines);
	return (lines);
}

int	read_n_lines(char *file, int lines, int dif)
{
	int		i;
	int		fd;
	char	*read_line;

	printf("\n");
	printf("testing file: \"%s\"\n", file);
	printf("reading %d + %d lines\n\n", lines, dif);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("error opening file\n");
	i = 0;
	while (i < lines + dif)
	{
		read_line = get_next_line(fd);
		print_line(read_line);
		free(read_line);
		i++;
	}
	close(fd);
	printf("\n");
	return (lines);
}

int	main(void)
{
	// g_fd_out = open("test_files/output", O_WRONLY | O_APPEND | O_CREAT);
	// if (g_fd_out == -1)
	// 	printf("error opening output file\n");
	// read_whole_file("./test_files/bible.txt", 99809);
	read_whole_file("./test_files/oneline", 1);
	read_whole_file("./test_files/ez", 5);
	read_whole_file("./test_files/letters", 26);
	// read_whole_file("./test_files/longline", 3);
	read_whole_file("./test_files/one_nl", 1);
	read_whole_file("./test_files/ten_nl", 10);
	read_whole_file("./test_files/empty", 0);
	read_n_lines("./test_files/ez", 5, 2);
	read_n_lines("./test_files/ez", 5, -2);
	close(g_fd_out);
}
