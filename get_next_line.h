/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:53:28 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/07 20:53:31 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

void	clear_buffer(char *buffer);
size_t	ft_strlen(char *str);
int		create_line(char **line_ptr, char *buffer, size_t size);
int		manage_buffer(char *buffer);
char	*get_next_line(int fd);

#endif