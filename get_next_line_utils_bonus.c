/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:45:42 by mouaammo          #+#    #+#             */
/*   Updated: 2022/11/06 11:35:30 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) >= ft_strlen(s))
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

char	*str_join(char *s1, char *s2)
{
	size_t		total;
	char		*join;
	size_t		i;
	size_t		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (total + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
		join[i + j] = s2[j];
	free(s1);
	s1 = NULL;
	join[i + j] = '\0';
	return (free(s2), s2 = NULL, join);
}

char	*get_reminder(char **str, int len)
{
	char	*tmp;
	int		rlen;

	if (!str || !(*str))
		return (NULL);
	tmp = NULL;
	rlen = ft_strlen(*str + len);
	tmp = ft_substr(*str, len, rlen);
	return (free(*str), *str = NULL, tmp);
}
