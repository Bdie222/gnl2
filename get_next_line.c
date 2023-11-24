/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiez-de <bdiez-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:35:29 by gganteau          #+#    #+#             */
/*   Updated: 2023/11/24 13:19:10 by bdiez-de         ###   ########.fr       */
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
	if(bytesRead <= 0)
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
			line = ft_substr(rest, 0, (rest - delimiter) + 1); // crea la linea limpia: desde la posicion 0 hasta delimiter (ie '\n')
			temp = rest;
			rest = ft_strdup(delimiter + 1); // rest ahora es todo lo que queda despues de delimiter (ie '\n')
			free(temp);
			return (line);
		}
		bytesRead = read(fd, buffer, BUFFER_SIZE);
	}
	if (rest != NULL && ft_strlen(rest) > 0)
	{
			temp = rest;
			rest = "";
			return (temp);
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
	//printf("3-  %s", get_next_line(fd));
	//printf("4-  %s", get_next_line(fd));
	//printf("5-  %s", get_next_line(fd));
	return (0);

}*/