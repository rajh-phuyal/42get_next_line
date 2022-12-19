/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:49:15 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/19 21:14:58 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* if the buffersize is not manully defined during compilation*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* necessary libraries */
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>

/* function prototypes */
void	clear_buffer(char *buffer);
size_t	ft_strlen(char *str);
int		create_line(char **line_ptr, char *buffer, size_t size);
int		manage_buffer(char *buffer);
char	*get_next_line(int fd);

#endif