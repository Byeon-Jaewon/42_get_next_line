/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:45:22 by jbyeon            #+#    #+#             */
/*   Updated: 2021/02/23 17:50:28 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		split(char **backup, char **line, int nlidx)
{
	char			*tmp;

	(*backup)[nlidx] = '\0';
	*line = ft_strdup(*backup);
	tmp = ft_strdup(*backup + nlidx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		unsplit(char **backup, char **line)
{
	*line = *backup;
	*backup = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup;
	char			buf[BUFFER_SIZE + 1];
	int				size;
	int				nlidx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		backup = ft_strjoin(backup, buf);
		nlidx = ft_strchr(backup, '\n');
		if (nlidx >= 0)
			return (split(&backup, line, nlidx));
	}
	if (size < 0)
		return (-1);
	if (backup != NULL && (nlidx = ft_strchr(backup, '\n')) >= 0)
		return (split(&backup, line, nlidx));
	if (backup != NULL)
		return (unsplit(&backup, line));
	*line = ft_strdup("");
	return (0);
}
