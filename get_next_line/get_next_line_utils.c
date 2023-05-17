/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:25 by skioridi          #+#    #+#             */
/*   Updated: 2023/05/17 18:03:07 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] || str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_join_nl(char *line, char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = (char *)malloc(ft_strlen_nl(line) + ft_strlen_nl(buffer) + 1);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while ((++i < ft_strlen_nl(line)) && line)
		new[i] = line[i];
	while ((++j < ft_strlen_nl(buffer)) && buffer)
		new[i + j] = buffer[j];
	if (buffer[j] == '\n')
		new[++i + j] = '\n';
	new[++i + j] = '\0';
	free(line);
	return (new);
}

int	nlcheck(char *buffer)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		buffer[i++] = '\0';
	if (buffer[i] == '\n')
	{
		found = 1;
		buffer[i++] = '\0';
		while (buffer[i])
		{
			buffer[j++] = buffer[i];
			buffer[i++] = '\0';
		}
	}
	return (found);
}
