/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:38:31 by jbyeon            #+#    #+#             */
/*   Updated: 2021/03/03 11:38:48 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			split(char **backup, char **line, int nlidx)
{
	char	*tmp;

	(*backup)[nlidx] = '\0';
	*line = ft_strdup(*backup);
	tmp = ft_strdup(*backup + nlidx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int			unsplit(char **backup, char **line)
{
	*line = *backup;
	*backup = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				size;
	int				nlidx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		nlidx = ft_strchr(backup[fd], '\n');
		if (nlidx >= 0)
			return (split(&backup[fd], line, nlidx));
	}
	if (size < 0)
		return (-1);
	if (backup[fd] != NULL && (nlidx = ft_strchr(backup[fd], '\n')) >= 0)
		return (split(&backup[fd], line, nlidx));
	if (backup[fd] != NULL)
		return (unsplit(&backup[fd], line));
	*line = ft_strdup("");
	return (0);
}
