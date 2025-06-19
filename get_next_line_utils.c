/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:27:35 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/19 18:22:50 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnl_char_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_uint	ft_gnl_strlen(const char *s)
{
	t_uint	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_gnl_str_append(char *dst, const char *src)
{
	char	*append;
	char	*appendp;
	char	*dstp;
	t_uint	len;

	len = ft_gnl_strlen(dst) + ft_gnl_strlen(src);
	append = (char *)malloc(sizeof(*append) * (len + 1));
	if (append == NULL)
		return (NULL);
	appendp = append;
	dstp = dst;
	while (dstp && *dstp)
		*appendp++ = *dstp++;
	while (*src)
		*appendp++ = *src++;
	*appendp = '\0';
	if (dst != NULL)
		free(dst);
	return (append);
}

char	*ft_gnl_substr(const char *s, t_uint start, t_uint len)
{
	char	*sub;
	size_t	i;

	sub = (char *)malloc(sizeof(*sub) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
