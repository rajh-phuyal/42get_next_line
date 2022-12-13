/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:03 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/13 14:58:49 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

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