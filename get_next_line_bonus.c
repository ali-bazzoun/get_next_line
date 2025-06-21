/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 07:54:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/21 08:53:43 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	**get_repo(t_list **list, int fd)
{
	t_list	*current;
	t_list	*new;

	current = *list;
	while (current)
	{
		if (current->fd == fd)
			return (&current->repo);
		current = current->next;
	}
	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->repo = NULL;
	new->next = *list;
	*list = new;
	return (&new->repo);
}

static void	*free_repo(char **repo_ptr)
{
	free(*repo_ptr);
	*repo_ptr = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*repo_list;
	char			**repo_ptr;
	char			buffer[BUFFER_SIZE + 1];
	int				nread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	repo_ptr = get_repo(&repo_list, fd);
	if (repo_ptr == NULL)
		return (NULL);
	while (ft_gnl_char_index(*repo_ptr, '\n') == -1)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread <= 0)
			break;
		buffer[nread] = '\0';
		*repo_ptr = ft_gnl_str_append(*repo_ptr, buffer);
		if (*repo_ptr == NULL)
			return (NULL);
	}
	if (*repo_ptr == NULL)
		return (NULL);
	if (**repo_ptr == '\0')
		return (free_repo(repo_ptr));
	return (ft_gnl_line_pop(repo_ptr));
}
