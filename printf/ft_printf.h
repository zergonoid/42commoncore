/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:52:12 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/27 22:34:42 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXL "0123456789ABCDEF"
# define HEXS "0123456789abcdef"

int	ft_printf(const char *s, ...);
int	*ft_putlchar(char c, int *len);
int	*ft_putlnbr(int nb, int *len);
int	*ft_putlhex(int nb, char *hex, int *len);
int	*ft_putlstr(char *s, int *len);
int	*ft_putladd(size_t add, int *len);

#endif