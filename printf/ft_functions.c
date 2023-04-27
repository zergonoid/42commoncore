/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:04:34 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/27 22:35:12 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_putlchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
	return (len);
}

int	*ft_putlnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putlchar('-', len);
		ft_putlchar('2', len);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putlchar('-', len);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putlnbr(nb / 10, len);
		ft_putlnbr(nb % 10, len);
	}
	else
	{
		ft_putlchar(nb + '0', len);
	}
	return (len);
}

int	*ft_putlhex(int nb, char *hex, int *len)
{
	if (nb == -2147483648)
	{
		ft_putlchar('-', len);
		ft_putlchar(hex[2], len);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putlchar('-', len);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putlnbr(nb / 16, len);
		ft_putlnbr(nb % 16, len);
	}
	else
	{
		ft_putlchar(hex[nb + '0'], len);
	}
	return (len);
}

int	*ft_putlstr(char *s, int *len)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		write(1, &s[i], 1);
	*len += i;
	return (len);
}

int	*ft_putladd(size_t add, int *len)
{
	ft_putlstr("0x", len);
	ft_putlhex(add, HEXS, len);
	return (len);
}
