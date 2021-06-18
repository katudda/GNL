/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 22:17:35 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/17 16:56:06 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (ptr);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	return ((char *)ft_memcpy(ptr, (unsigned char *)str, len));
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*dsrc;
	char	*ddst;
	size_t	c;

	c = 0;
	dsrc = (char *) src;
	ddst = (char *) dst;
	if (!dsrc && !ddst)
		return (NULL);
	while (c < n)
	{
		ddst[c] = dsrc[c];
		c++;
	}
	return (dst);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (0);
}
