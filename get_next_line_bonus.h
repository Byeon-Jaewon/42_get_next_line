/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:32:57 by jbyeon            #+#    #+#             */
/*   Updated: 2021/02/08 22:35:32 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

int				get_next_line(int fd, char **line);
int	            ft_strchr(const char *s, int c);
char	        *ft_substr(char const *s, unsigned int start, size_t len)

size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
char			*ft_strdup(char *s1);
char	        *ft_strjoin(char const *s1, char const *s2);

#endif
