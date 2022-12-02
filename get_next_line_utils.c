/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:53 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/02 14:20:47 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	unsigned int len;

	len = 0;
	while (str[len])
	{
		if (str[len] != '\n')
			return (len + 1);
		len++;
	}
	return (len);
}

int	create_line(char **line_ptr, char *buffer, int size)
{
	char	*l_alias;
	int		i;
	int		j;

	i = 0;
	l_alias = *line_ptr;
	*line_ptr = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(l_alias) + 1));
	if (!(*line_ptr))
		return (0);
	while (*l_alias && l_alias)
		(*line_ptr)[i++] = *l_alias++;
	j = 0;
	while (j < size)
	{
		(*line_ptr)[i++] = buffer[j++];
		
	(*line_ptr)[i] = '\0';
	
}