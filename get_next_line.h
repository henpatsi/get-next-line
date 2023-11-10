/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:56:12 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/10 15:38:12 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

ssize_t	get_nl_index(char *s, size_t size, size_t i);
char	*dup_buf(char *s, size_t start, size_t end);
char	*add_buf(char *s1, char *s2, size_t size1, size_t size2);

#endif