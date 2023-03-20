/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:26:54 by mouaammo          #+#    #+#             */
/*   Updated: 2022/11/06 12:02:42 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*stash[OPEN_MAX];
	int				bytes;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX
		|| read(fd, NULL, 0) < 0)
		return (NULL);
	line = NULL;
	while (check_new_line(stash[fd]) == -1)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes = (int) read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = 0;
		stash[fd] = str_join(stash[fd], buffer);
		if (!bytes && stash[fd] && !stash[fd][0])
			break ;
		if (!bytes)
			return (get_reminder(&stash[fd], 0));
	}
	if (check_new_line(stash[fd]) != -1)
		return (get_my_line(&stash[fd], line, check_new_line(stash[fd])));
	return (free(stash[fd]), stash[fd] = NULL, NULL);
}

int	check_new_line(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_my_line(char **temp, char *line, int ln)
{
	if (!temp)
		return (NULL);
	line = ft_substr(*temp, 0, ln + 1);
	*temp = get_reminder(temp, ln + 1);
	return (line);
}
