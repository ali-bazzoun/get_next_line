/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:19:19 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/19 18:24:49 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*residue;
	char		buffer[BUFFER_SIZE + 1];
	char		*newline;
	char		*sub;
	int			nread;

	nread = read(fd,  buffer, BUFFER_SIZE);
	if (nread == 0 && ft_gnl_char_index(residue, '\n') == -1)
	{
		free(residue);
		return (NULL);
	}
	buffer[nread] = '\0';
	residue = ft_gnl_str_append(residue, buffer);
	if (residue == NULL)
		return (NULL);
	if (ft_gnl_char_index(residue, '\n') == -1)
		return (get_next_line(fd));
	newline = ft_gnl_substr(residue, 0, (t_uint) ft_gnl_char_index(residue, '\n') + 1);
	sub = ft_gnl_substr(residue, (t_uint) ft_gnl_char_index(residue, '\n') + 1, ft_gnl_strlen(residue));
	if (sub == NULL)
		return (NULL);
	free(residue);
	residue = sub;
	return (newline);
}
