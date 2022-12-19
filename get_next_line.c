/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:53:38 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/19 21:14:55 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
the get next line function uses a static array to keep track of the
offset of the file discriptor and also returns the current line.
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		clear_buffer(buffer);
		return (NULL);
	}
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