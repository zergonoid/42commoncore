/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steffi <steffi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:22 by steffi            #+#    #+#             */
/*   Updated: 2023/05/09 17:05:14 by steffi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*temp;
	int			i;

	if (fd < 0)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, temp, BUFFER_SIZE);
	ft_findsize(temp);
	while (temp[++i] != '\n')
		next_line[i] = temp[i];
	next_line[i] = '\0';
	return (next_line);
}
