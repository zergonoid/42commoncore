/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:48:29 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/14 18:42:59 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

int	get_wordno(char *str, char c)
{
	int	w;

	w = 0;
	while (*str)
	{
		while (*str != c)
			str++;
		w++;
	}
	return (w);
}

char	*wordpaste(char *word, char *full, char c)
{
	while (*full != c)
	{
		*word = *full;
		full++;
		word++;
	}
	*word = 0;
	return (full);
}

int	get_next_wordlen(char *full, char c)
{
	int	len;

	len = 0;
	while (*full != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*trim;
	int		wordno;
	int		wordlen;
	int		i;

	i = 0;
	trim = ft_strtrim(s, &c);
	wordno = get_wordno(trim, c);
	wordlen = get_next_wordlen(trim, c);
	new = malloc(wordno + 1);
	if (!new)
		return (NULL);
	while (i <= wordno)
	{
		new[i] = malloc(wordlen + 1);
		if (!new[i])
			return (NULL);
		trim = wordpaste(new[i], trim, c);
		i++;
	}
	new[i] = 0;
	return (new);
}
