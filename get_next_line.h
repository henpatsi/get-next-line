/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:10:29 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/14 15:10:29 by hpatsi           ###   ########.fr       */
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
ssize_t	ft_i_strchr(const char *s, int c);
char	*ft_strldup(const char *s1, size_t len);
char	*ft_stradd(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(char *s, size_t len);

#endif