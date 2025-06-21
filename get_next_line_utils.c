/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:27:35 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/21 07:13:42 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_uint	ft_gnl_strlen(const char *s)
{
	t_uint	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_gnl_substr(const char *s, t_uint start_index, t_uint sub_len)
{
	char	*sub;
	char	*p;
	int		sub_leni;

	sub = (char *)malloc(sizeof(*sub) * ( sub_len + 1));
	if (sub == NULL)
		return (NULL);
	sub_leni = (int) sub_len;
	p = sub;
	s += start_index;
	while (sub_leni--)
		*p++ = *s++;
	*p = '\0';
	return (sub);
}

int	ft_gnl_char_index(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (-1);
}

char	*ft_gnl_str_append(char *dst, const char *src)
{
	char	*append;
	char	*dstp;
	char	*p;
	int		dst_len;
	int		src_len;

	dst_len = (int) ft_gnl_strlen(dst);
	src_len = (int) ft_gnl_strlen(src);
	append = (char *)malloc(sizeof(*append) * (dst_len + src_len + 1));
	if (append == NULL)
		return (NULL);
	p = append;
	dstp = dst;
	while (dst_len--)
		*p++ = *dstp++;
	while (src_len--)
		*p++ = *src++;
	*p = '\0';
	if (dst != NULL)
		free(dst);
	return (append);
}

char	*ft_gnl_line_pop(char **repo)
{
	char	*str;
	char	*line;
	char	*rest;
	int		index;
	int		len;

	str = *repo;
	len = ft_gnl_strlen(str);
	index = ft_gnl_char_index(str, '\n');
	if (index == -1)
		index = len - 1;
	line = ft_gnl_substr(str, 0, index + 1);
	if (line == NULL)
		return (NULL);
	rest = ft_gnl_substr(str, index + 1, len - index - 1);
	if (rest == NULL)
		return (NULL);
	free(str);
	*repo = rest;
	return (line);
}
