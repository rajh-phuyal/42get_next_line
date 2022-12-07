/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:53 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/07 20:48:29 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_buffer(char *buffer)
{
	size_t	index;

	index = 0;
	if (!buffer)
		return ;
	while (index <= BUFFER_SIZE)
		buffer[index++] = '\0';
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != 10)
		len++;
	return (len + (str[len] == 10));
}

int	manage_buffer(char *buffer)
{
	char	*start;
	char	*temp;

	start = buffer;
	while (*buffer)
	{
		if (*buffer == 10)
		{
			*buffer = '\0';
			temp = buffer + 1;
			while (*temp)
			{
				*start++ = *temp;
				*temp++ = '\0';
			}
			return (1);
		}
		else
			*buffer++ = '\0';
	}
	return (0);
}

int	create_line(char **line_ptr, char *buffer, size_t size)
{
	char	*l_alias;
	int		inew;
	int		iold;
	size_t	ibuff;

	inew = 0;
	l_alias = *line_ptr;
	*line_ptr = malloc(sizeof(char) * (size + ft_strlen(l_alias) + 1));
	if (!(*line_ptr))
		return (0);
	if (l_alias)
	{
		iold = 0;
		while (l_alias[iold])
			(*line_ptr)[inew++] = l_alias[iold++];
		free(l_alias);
	}
	ibuff = 0;
	while (ibuff < size)
		(*line_ptr)[inew++] = buffer[ibuff++];
	(*line_ptr)[inew] = '\0';
	return (manage_buffer(buffer));
}
