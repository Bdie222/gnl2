/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiez-de <bdiez-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:35:29 by gganteau          #+#    #+#             */
/*   Updated: 2023/11/29 16:00:07 by bdiez-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
		return(NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_rhcrts(const char *s, int c)
{
	int	i;
	char	*str;

	i = 0;
	if(!s)
		return(NULL);
	while (s[i] && s[i - 1] != c)
	{
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if(!str)
		return(NULL);
	i = 0;
	while (s[i] && s[i - 1] != c)
	{
		//printf("s[i] = %c\n", s[i]);
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
		return(0);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	if (s2[j] == '\n')
	{
		s3[i] = '\n';
		s3[i+1] = '\0';
	}
	return (s3);
}

char	*ft_strdup(const char *s1)
{	
	size_t	i;
	size_t	j;
	char	*dup;

	i = ft_strlen(s1);
	//printf("s = %s | i = %zu\n", s1, i);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = s1[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
char	*ft_strdup2(const char *s1)
{	
	size_t	i;
	size_t	j;
	char	*dup;

	i = 0;
	//printf("s = %s", s1);
	while (s1[i] && s1[i] != '\n')
	{
		i++;
	}
	if (s1[i] == '\n')
		i++;
	//printf("\ni = %zu", i);
	//printf("\nalloc = %zu", alloc);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = s1[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*new_str;
	size_t	slen;

	j = 0;
	slen = ft_strlen(s);
	if (!s)
		return (0);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (j < len)
	{
		new_str[j] = s[start];
		j++;
		start++;
	}
	new_str[j] = '\0';
	return (new_str);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}