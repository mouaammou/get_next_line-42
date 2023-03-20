/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:47:07 by mouaammo          #+#    #+#             */
/*   Updated: 2022/11/06 11:44:23 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		check_new_line(char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*str_join(char *s1, char *s2);
char	*get_reminder(char **str, int len);
char	*get_my_line(char **temp, char *line, int ln);

#endif
