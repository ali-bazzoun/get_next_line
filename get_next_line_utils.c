/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:27:35 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/20 16:17:57 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_uint	ft_gnl_strlen(const char *s)
{
	t_uint	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_substr(const char *s, t_uint start_index, t_uint len)
{
	char	*sub;
	size_t	i;

	sub = (char *)malloc(sizeof(*sub) * ((len - start_index) + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len - start_index)
	{
		sub[i] = s[start_index + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_gnl_char_index(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_gnl_str_append(char *dst, const char *src)
{
	char	*append;
	t_uint	append_len;
	t_uint	i;
	t_uint	j;

	append_len = ft_gnl_strlen(dst) + ft_gnl_strlen(src);
	append = (char *)malloc(sizeof(*append) * (append_len + 1));
	if (append == NULL)
		return (NULL);
	i = 0;
	while (i < ft_gnl_strlen(dst))
	{
		append[i] = dst[i];
		i++;
	}
	j = 0;
	while (src[j])
		append[i++] = src[j++];
	append[i] = '\0';
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

	str = *repo;
	index = ft_gnl_char_index(str, '\n');
	if (index == -1)
		index = ft_gnl_strlen(str) - 1;
	line = ft_gnl_substr(str, 0, index + 1);
	if (line == NULL)
		return (NULL);
	rest = ft_gnl_substr(str, index + 1, ft_gnl_strlen(str));
	if (rest == NULL)
		return (NULL);
	free(str);
	*repo = rest;
	return (line);
}
