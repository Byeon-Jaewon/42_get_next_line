/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:45:07 by jbyeon            #+#    #+#             */
/*   Updated: 2021/03/03 11:35:47 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

int			get_next_line(int fd, char **line);
int			ft_strchr(char *s, int c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *src);

#endif
