/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:53 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/06 23:46:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	putnull(char *buffer)
{
	size_t	index;

	while (index < BUFFER_SIZE)
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
	if (str[len] == 10)
		len++;
	return (len);
}

int	buff_check(char *buffer)
{
	char	*start;
	char	*temp;

	while (*buffer)
	{
		if (*buffer == 10)
		{
			*buffer = '\0';
			temp = buffer + 1;
			while (*temp)
				*start++ = *temp++;
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
	return (buff_check(buffer));
}
