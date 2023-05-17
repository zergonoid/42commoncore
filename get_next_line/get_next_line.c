/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:22 by skioridi          #+#    #+#             */
/*   Updated: 2023/05/17 16:22:46 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;
	int			pos;
	int			r;

	if (!checkfd(fd, buffer))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	pos = -1;
	i = -1;
	line = NULL;
	buffer = NULL;
	while (pos == -1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (!r)
			return (NULL);
		pos = ft_findnew(buffer);
		if (pos == -1)
			line = ft_strjoin(line, buffer);
		else
		{
			while (++i <= pos)
			{
				*line = buffer[i];
				line++;
			}
		}
	}
	buffer = &buffer[pos + 1];
	return (line);
}

int	checkfd(int fd, char *buffer)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		check;

// 	check = 1;
// 	fd = open("text.txt", O_RDONLY);
// 	printf("\nBuff_size: %d\n", BUFFER_SIZE);
// 	while (check)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 		{
// 			check = 0;
// 			printf("\n");
// 		}
// 		printf("Line: %s", line);
// 		free(line);
// 	}
// }
