/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steffi <steffi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:25 by steffi            #+#    #+#             */
/*   Updated: 2023/05/09 17:11:21 by steffi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findnew(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' || str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = -1;
	t = s;
	while (++i < n)
		t[i] = '\0';
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	newlen;
	size_t	i;
	size_t	j;

	newlen = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(newlen + 1);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		new[i] = s1[i];
	while (++j < ft_strlen(s2))
		new[i + j] = s2[j];
	new[i + j] = 0;
	return (&new[i + j]);
}
