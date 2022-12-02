/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:03 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/02 14:19:11 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			read_res;

	if (fd < 0 || BUFFER_SIZE < 1 || fcntl(fd, O_NONBLOCK))
		return (NULL);
	line = NULL;
	while (true)
	{
		if (*buffer)
		{
			if (create_line(&line, buffer, ft_strlen(buffer)))
				break ;
		}
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (!read_res)
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
	line = get_next_line(fd);
	while (1)
	{
		if (!line)
			break;
		printf("%s", line);
		line = get_next_line(fd);
	} 
	if (line)
		free (line);
}
*/