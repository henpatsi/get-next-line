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
#include <string.h>

#include "get_next_line.h"

int	g_fd_out;
int	malloc_count;

void	*unreliable_malloc(size_t size)
{
	malloc_count += 1;
	if (malloc_count % 10 == 0)
		return (0);
	return (malloc(size));
}

void	print_line(char *str)
{
	write(1, "line: ", 6);
	if (str == 0)
		write(1, "(null)", 6);
	else
	{
		while (*str != 0)
		{
			if (*str == '\n')
				write(1, "\\n", 2);
			else
				write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
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
		read_line = (char *)&fd;
		while (read_line != 0)
		{
			read_line = get_next_line(fd);
			if (read_line != 0)
				lines--;
			print_line(read_line);
			//write_to_file(read_line);
			free(read_line);
		}
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

int	read_multiple_files(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*read_line;
	int		i;

	fd1 = open("./test_files/123", O_RDONLY);
	if (fd1 == -1)
		printf("error opening file\n");
	fd2 = open("./test_files/456nl", O_RDONLY);
	if (fd2 == -1)
		printf("error opening file\n");
	fd3 = open("./test_files/simple_lines", O_RDONLY);
	if (fd3 == -1)
		printf("error opening file\n");
	i = 0;
	while (i < 5)
	{
		printf("\n");
		read_line = get_next_line(fd1);
		printf("fd = %d\n", fd1);
		print_line(read_line);
		free(read_line);
		printf("fd = %d\n", fd2);
		read_line = get_next_line(fd2);
		print_line(read_line);
		free(read_line);
		printf("fd = %d\n", fd3);
		read_line = get_next_line(fd3);
		print_line(read_line);
		free(read_line);
		i++;
	}

	return (0);
}

int	read_from_stdoutin(int fd)
{
	char	*read_line;
	char	c;

	c = 'a';
	read_line = &c;
	while (read_line != 0)
	{
		read_line = get_next_line(fd);
		print_line(read_line);
		free(read_line);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "input") == 0)
		{
			printf("reading from stdin\n");
			read_from_stdoutin(0);
		}
		return (0);
	}

	// g_fd_out = open("test_files/output", O_WRONLY | O_APPEND | O_CREAT);
	// if (g_fd_out == -1)
	// 	printf("error opening output file\n");

	printf("\n\n --------- SINGLE FILE TESTS ---------\n");
	// read_whole_file("./test_files/bible", 99809);
	read_whole_file("./test_files/longline", 3);
	read_whole_file("./test_files/oneline", 1);
	read_whole_file("./test_files/123", 3);
	read_whole_file("./test_files/456nl", 3);
	read_whole_file("./test_files/simple_lines", 4);
	read_whole_file("./test_files/letters", 26);
	read_whole_file("./test_files/everyother", 9);
	read_whole_file("./test_files/one_nl", 1);
	read_whole_file("./test_files/ten_nl", 10);
	read_whole_file("./test_files/empty", 0);
	read_whole_file("./test_files/linelength41", 5);
	read_whole_file("./test_files/linelength42", 5);
	read_whole_file("./test_files/linelength43", 5);

	// read_n_lines("./test_files/simple_lines", 4, 2);
	//read_n_lines("./test_files/ez", 5, -2);
	//read_whole_file("./test_files/123", 3);
	// close(g_fd_out);

	printf("\n\n--------- MULTIPLE FILES TESTS ---------\n");
	read_multiple_files();

	return (0);
}
