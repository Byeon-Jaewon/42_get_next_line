/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:31:40 by jbyeon            #+#    #+#             */
/*   Updated: 2021/02/09 22:30:16 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		split(char **backup, char **line, char *ptr)
{
	char	*tmp;

	ptr = '\0';
	*line = ft_strdup(*backup);
	if (ft_strlen(ptr + 1) == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup(ptr + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		unsplit(char **backup, char **line)
{
	char	*ptr;

	if ((*backup != NULL) && (ptr = ft_strchr(*backup, '\n')) != NULL)
		return (split(backup, line, ptr));
	else if (*backup != NULL)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				size;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((ptr = ft_strchr(*backup, '\n')) != NULL)
			return (split(&backup[fd], line, ptr));
	}
	if (size < 0)
		return (-1);
	return (unsplit(&backup[fd], line));
}
