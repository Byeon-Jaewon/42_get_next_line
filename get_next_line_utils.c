/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:45:15 by jbyeon            #+#    #+#             */
/*   Updated: 2021/02/23 16:49:33 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp1;
	char	*tmp2;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	if ((tmp1 == NULL) || (tmp2 == NULL))
		return (!(tmp1) ? ft_strdup(tmp2) : ft_strdup(tmp1));
	size = ft_strlen(tmp1) + ft_strlen(tmp2);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	str[0] = '\0';
	ft_strlcat(str, tmp1, ft_strlen(tmp1) + 1);
	ft_strlcat(str, tmp2, ft_strlen(str) + ft_strlen(tmp2) + 1);
	return (str);
}

char		*ft_strdup(char *src)
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

int			ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
