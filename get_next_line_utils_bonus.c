#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*tmp;

	len = ft_strlen(src);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	j = 0;
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp1;
	char	*tmp2;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	size = ft_strlen(tmp1) + ft_strlen(tmp2);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	str[0] = '\0';
	ft_strlcat(str, tmp1, ft_strlen(tmp1) + 1);
	ft_strlcat(str, tmp2, ft_strlen(str) + ft_strlen(tmp2) + 1);
	return (str);
}