/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiez-de <bdiez-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:35:29 by gganteau          #+#    #+#             */
/*   Updated: 2023/11/29 15:58:48 by bdiez-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char *rest = NULL; // la norma permite inicializar una static
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytesRead;
	char *temp;
	char *delimiter;
	char *line;

	if (fd < 0)
		return NULL;
	//if (rest == NULL) // rest estara vacia en la primera leida. 
	//	rest = ft_strdup(""); // para poder usar rest y que se inicie el bucle, duplicamos un string vacio en la primera leida.
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	if(bytesRead <= 0 && rest == NULL)
		return (NULL);
	while (bytesRead > 0)
	{
		buffer[bytesRead] = '\0'; //acabar buffer en '\0' para evitar desbordes de memoria a medida que se van concatenando leidas
		if (rest == NULL) // rest estara vacia en la primera leida. 
			rest = ft_strdup("");
		temp = rest; //debido a que rest hay que limpiarla de leidas previas hasta '\n', necesitamos temp para almacenar el contenido temporalmente y luego liberar la memoria
		rest = ft_strjoin(rest, buffer);
		free(temp);
		delimiter = ft_strchr(rest, '\n'); //delimiter nos va a establecer la distancia entre la posicion 0 y el primer '\n' encontrado en rest
		if (delimiter != NULL)
		{
			//printf("\nrest:%s\ncoso: %s|\n", rest, ft_rhcrts(rest, '\n'));
			//line = ft_substr(rest, 0, (rest - delimiter) + 1); // crea la linea limpia: desde la posicion 0 hasta delimiter (ie '\n')
			line = ft_strdup2(rest);
			temp = rest;
			//printf("delimiter: %s|\n", (delimiter + 1));
			if(ft_strlen(delimiter) > 1)
				rest = ft_strdup(delimiter + 1);
			else
				rest = NULL;
			//printf("rest: %s|\n", rest);
			free(temp);
			return (line);
		}
		bytesRead = read(fd, buffer, BUFFER_SIZE);
	}
	//printf("xrest: %s|\n", rest);
	if (rest != NULL && ft_strlen(rest) > 0)
	{
		if (!ft_strchr(rest, '\n'))
		{
			temp = rest;
			rest = "";
			return (temp);
		}
		delimiter = ft_strchr(rest, '\n');
		line = ft_substr(rest, 0, (rest - delimiter) + 1);
		//printf("line: %s|\n", line);
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

	fd = open("tester.txt", O_RDONLY);
	printf("1-  %s", get_next_line(fd));
	printf("2-  %s", get_next_line(fd));
	printf("3-  %s", get_next_line(fd));
	printf("4-  %s", get_next_line(fd));
	printf("5-  %s", get_next_line(fd));
	return (0);
}*/