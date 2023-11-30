/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiez-de <bdiez-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:35:29 by gganteau          #+#    #+#             */
/*   Updated: 2023/11/30 12:24:49 by bdiez-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char *rest = NULL;
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytesRead;
	char *temp;
	char *delimiter;
	char *line;

	if (fd < 0)
		return NULL;
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	if(bytesRead <= 0 && rest == NULL)
		return (0);
	while (bytesRead > 0)
	{
		buffer[bytesRead] = '\0';
		if (rest == NULL)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(rest, buffer);
		free(temp);
		delimiter = ft_strchr(rest, '\n');
		if (delimiter != NULL)
		{
			line = ft_strdup2(rest);
			temp = rest;
			if(ft_strlen(delimiter) > 1)
				rest = ft_strdup(delimiter + 1);
			else
				rest = NULL;
			free(temp);
			return (line);
		}
		bytesRead = read(fd, buffer, BUFFER_SIZE);
	}
	if (rest != NULL && ft_strlen(rest) > 0)
	{
		if (!ft_strchr(rest, '\n'))
		{
			temp = rest;
			rest = "";
			return (temp);
		}
		delimiter = ft_strchr(rest, '\n');
		line = ft_strdup2(rest);
		temp = rest;
		if(ft_strlen(delimiter) > 1)
			rest = ft_strdup(delimiter + 1);
		else
			rest = NULL;
		free(temp);
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
	char 	*hola = NULL;

	fd = open("rde.txt", O_RDONLY);
	while(i <= 5)
	{
		printf("%i- %s", i, get_next_line(fd));
		i++;
	}
	return (0);
}*/