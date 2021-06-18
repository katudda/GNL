/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:19:31 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/17 18:50:58 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char			*buffer;
	char			*temp;
	ssize_t			size;
}	t_gnl;

char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif