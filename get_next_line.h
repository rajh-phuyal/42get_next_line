/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:55 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/06 23:43:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

void	putnull(char *buffer);
size_t	ft_strlen(char *str);
int		create_line(char **line_ptr, char *buffer, size_t size);
int		buff_check(char *buffer);
char	*get_next_line(int fd);

#endif