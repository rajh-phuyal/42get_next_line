/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nexus <nexus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:53 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/05 01:47:05 by nexus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
	{
		if (str[len] == 10)
			return (len + 1);
		len++;
	}
	return (len);
}

void	reset_buffer_contents(char *buffer, int size)
{
	int	pos;
	int	start;

	start = 0;
	pos = ft_strlen(buffer) - 1;
	if (buffer[pos] == 10)
	{
		while (start < size && buffer[pos])
			buffer[start++] = buffer[pos++];
		while (start < size)
			buffer[start++] = 0;
	}
}

int	create_line(char **line_ptr, char *buffer, size_t size)
{
	char	*l_alias;
	int		i;
	int		iold;
	size_t	j;

	i = 0;
	l_alias = *line_ptr;
	*line_ptr = malloc(sizeof(char) * (size + ft_strlen(l_alias) + 1));
	if (!(*line_ptr))
		return (0);
	if (l_alias)
	{
		iold = 0;
		while (l_alias[iold])
			(*line_ptr)[i++] = l_alias[iold++];
		free(l_alias);
	}
	j = 0;
	while (j < size)
		(*line_ptr)[i++] = buffer[j++];
	(*line_ptr)[i] = '\0';
	if ((*line_ptr)[i - 1] == 10)
		return (1);
	else
		return (0);
}
