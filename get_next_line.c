/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiez-de <bdiez-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:35:29 by gganteau          #+#    #+#             */
/*   Updated: 2023/12/12 17:12:54 by bdiez-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*dup;

	i = ft_strlen(s1);
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

void	reader(char *rest, char *buffer, char **prest, char **pline)
{
	char	*temp;
	char	*delimiter;
	char	*r;
	char	*l;

	r = NULL;
	l = NULL;
	if (rest == NULL)
		rest = ft_strdup("");
	temp = rest;
	r = ft_strjoin(rest, buffer);
	free(temp);
	delimiter = ft_strchr(r, '\n');
	if (delimiter != NULL)
	{
		l = ft_strdup2(r);
		temp = r;
		if (ft_strlen(delimiter) > 0)
			r = ft_strdup(delimiter);
		else
			r = NULL;
		free(temp);
	}
	*prest = r;
	*pline = l;
}

void	restmaker(char *rest, char *line, char **prest, char **pline)
{
	char	*temp;
	char	*delimiter;

	if (!ft_strchr(rest, '\n'))
	{
		temp = rest;
		rest = "";
		line = temp;
	}
	else
	{
		delimiter = ft_strchr(rest, '\n');
		line = ft_strdup2(rest);
		temp = rest;
		if (ft_strlen(delimiter) > 0)
			rest = ft_strdup(delimiter);
		else
			rest = NULL;
		free(temp);
	}
	*prest = rest;
	*pline = line;
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytesread;
	char		*line;

	if (fd < 0)
		return (NULL);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread <= 0 && rest == NULL)
		return (0);
	while (bytesread > 0)
	{
		buffer[bytesread] = '\0';
		reader(rest, buffer, &rest, &line);
		if (line)
			return (line);
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	if (rest != NULL && ft_strlen(rest) > 0)
	{
		restmaker(rest, line, &rest, &line);
		return (line);
	}
	rest = "";
	return (NULL);
}

/*
#include <fcntl.h>
int	main()
{
	int		fd;
	int		i = 1;

	fd = open("readerror.txt", O_RDONLY);
	while(i <= 10)
	{
		printf("%i- %s", i, get_next_line(fd));
		i++;
	}
	return (0);
}
*/