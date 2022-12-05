/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nexus <nexus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:55 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/05 01:33:35 by nexus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

size_t	ft_strlen(char *str);
int		create_line(char **line_ptr, char *buffer, size_t size);
void	reset_buffer_contents(char *buffer, int size);
char	*get_next_line(int fd);

#endif