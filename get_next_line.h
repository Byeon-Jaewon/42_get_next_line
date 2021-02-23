#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
int	        	ft_strchr(const char *s, int c);

size_t	    	ft_strlen(const char *s);
size_t		    ft_strlcat(char *dest, const char *src, size_t size);

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *src);

#endif