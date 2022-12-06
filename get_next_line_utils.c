/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:53 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/06 19:58:52 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != 10)
		len++;
	if (str[len] == 10)
		len++;
	return (len);
}

int	buff_check(char *buffer)
{
	unsigned int	index;
	unsigned int	indexj;
	unsigned int	size;

	index = 0;
	size = sizeof(buffer);
	while (index < size)
	{
		if (buffer[index] == 10)
		{
			indexj = 0;
			while (indexj < size - 1)
			{
				buffer[indexj] = buffer[indexj + index];
				buffer[indexj + index] = '\0';
				indexj++;
			}
			return (1);
		}
		buffer[index++] = '\0';
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
	*line_ptr = malloc(sizeof(char) * (size + ft_strlen(l_alias) + 2));
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
	return (buff_check(buffer));
}
