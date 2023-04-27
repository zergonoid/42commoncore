/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:04:34 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/28 00:24:31 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putlnbr(int nb, int *len)
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
		ft_putlchar(nb + '0', len);
}

void	ft_putluns(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putluns(nb / 10, len);
		ft_putluns(nb % 10, len);
	}
	else
		ft_putlchar(nb + '0', len);
}

void	ft_putlhex(long unsigned int nb, char *hex, int *len)
{
	if (nb / 16 == 0)
	{
		ft_putlchar(hex[nb % 16], len);
		return ;
	}
	else
	{
		ft_putlhex(nb / 16, hex, len);
		ft_putlchar(hex[nb % 16], len);
	}
}

void	ft_callputlhex(unsigned int nb, char *hex, int *len)
{
	long unsigned int	n;

	n = nb;
	ft_putlhex(n, hex, len);
}
