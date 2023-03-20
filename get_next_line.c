/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:46:08 by mouaammo          #+#    #+#             */
/*   Updated: 2022/11/06 12:10:09 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define  BUFFER_SIZE 5
#endif

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*stash;
	int				bytes;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read(fd, NULL, 0) < 0)
		return (NULL);
	line = NULL;
	while (check_new_line(stash) == -1)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes = (int) read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = 0;
		stash = str_join(stash, buffer);
		if (!bytes && !stash[0])
			break ;
		if (!bytes)
			return (get_reminder(&stash, 0));
	}
	if (check_new_line(stash) != -1)
		return (get_my_line(&stash, line, check_new_line(stash) + 1));
	return (free(stash), stash = NULL, NULL);
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
	line = ft_substr(*temp, 0, ln);
	*temp = get_reminder(temp, ln);
	return (line);
}
