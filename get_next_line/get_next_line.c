/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:22 by skioridi          #+#    #+#             */
/*   Updated: 2023/05/17 18:03:26 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			r;

	line = NULL;
	r = 1;
	if (fd < 0 || read(fd, 0, 0) <= 0 || BUFFER_SIZE < 1)
	{
		r = -1;
		while (buffer[++r])
			buffer[r] = 0;
		return (NULL);
	}
	while (r > 0)
	{
		if (!buffer[0])
			r = read(fd, buffer, BUFFER_SIZE);
		if (r > 0)
			line = ft_join_nl(line, buffer);
		if (nlcheck(buffer))
			break ;
	}
	return (line);
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
