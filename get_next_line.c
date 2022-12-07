/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nexus <nexus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:03 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/07 00:33:36 by nexus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (NULL);
	line = NULL;
	while (true)
	{
		if (*buffer)
		{
			if (create_line(&line, buffer, ft_strlen(buffer)))
				break ;
		}
		if (!read(fd, buffer, BUFFER_SIZE))
			break ;
	}
	return (line);
}

/*
char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (NULL);
	line = NULL;
	while (true)
	{
		if (!(*buffer))
		{
			if (!read(fd, buffer, BUFFER_SIZE))
				break ;
		}
		if (create_line(&line, buffer, ft_strlen(buffer)))
		{
			reset_buffer_contents(buffer, BUFFER_SIZE);
			break ;
		}
	}
	return (line);
}
*/
int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s\n", line);
	}
	if (line)
		free (line);
}
