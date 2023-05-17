/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steffi <steffi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:22 by steffi            #+#    #+#             */
/*   Updated: 2023/05/09 17:11:18 by steffi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;
	int 		pos;

	if (fd < 0 || read(fd, 0, 0) == 0 || BUFFER_SIZE < 1 )
	{
		ft_bzero(buffer, BUFFER_SIZE);
		return (NULL);
	}
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	pos = -1;
	line = NULL;
	while (pos == -1)
	{
		read(fd, buffer, BUFFER_SIZE);
		ft_strjoin(line, buffer);
		pos = ft_findnew(buffer);
	}
	buffer = &buffer[pos + 1];
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		check;

	check = 1;
	fd = open("text.txt", O_RDONLY);
	printf("\nBuff_size: %d\n", BUFFER_SIZE);
	while (check)
	{
		line = get_next_line(fd);
		if (!line)
		{
			check = 0;
			printf("\n");
		}
		printf("Line: %s", line);
		free(line);
	}
}
