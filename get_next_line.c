#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*backup;
	char			buf[BUFFER_SIZE + 1];
	int				size;
	int				nlidx;
	static int				cursor = 0;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	nlidx = ft_strchr(backup + cursor, '\n');
	if (nlidx >= 0)
	{
		backup[nlidx] = '\0';
		*line = ft_strdup(backup + cursor);
		cursor = cursor+ nlidx + 1;
		return (1);
	}
	else if ((backup + cursor)&& (nlidx < 0)) 
	{
		*line = ft_strdup(backup + cursor);
		
		return (0);
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}
/*
int	main()
{
	int		ret;
	int		fd;
	char	*line;

	fd = open("Your text", O_RDONLY);
	while ((ret = (get_next_line(fd, &line)) > 0))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
}*/