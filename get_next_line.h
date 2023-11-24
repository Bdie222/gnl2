/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiez-de <bdiez-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:36:25 by gganteau          #+#    #+#             */
/*   Updated: 2023/11/16 16:16:14 by bdiez-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#	define	GET_NEXT_LINE_H
#	include	<stddef.h>
#	include <unistd.h>
#	include <stdlib.h>

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 5
#	endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
int	ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
//static char *ft_read_and_rest(int fd, char *rest);

# endif