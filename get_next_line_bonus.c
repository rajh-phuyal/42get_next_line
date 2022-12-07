/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:03 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/07 21:11:27 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE];
	char		*line;

	//BUFFER_SIZE < 1 || read(fd, 0, 0) < 0
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		if ((fd >= 0 && fd <= FOPEN_MAX) || read(fd, 0, 0) >= 0)
			clear_buffer(buffer[fd]);
		return (NULL);
	}
	line = NULL;
	while (true)
	{
		if (*buffer[fd])
		{
			if (create_line(&line, buffer[fd], ft_strlen(buffer[fd])))
				break ;
		}
		if (!read(fd, buffer[fd], BUFFER_SIZE))
			break ;
	}
	return (line);
}

/*
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
			break ;
		printf("%s", line);
	}
	if (line)
		free (line);
}
*/