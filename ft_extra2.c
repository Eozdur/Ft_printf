/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <ozduremre06@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:17:05 by eozdur            #+#    #+#             */
/*   Updated: 2022/12/13 13:52:31 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %u unsigned integer için kullanılır
int	ft_u(unsigned int u)
{
	int	i;

	i = 0;
	if (u <= 9)
		i += ft_putchar(u + '0');
	else
	{
		i += ft_u(u / 10);
		i += ft_u(u % 10);
	}
	return (i);
}
// pointer için
// pointerları hex olarak yazmamız gerekiyor
int	ft_p(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += ft_p(p / 16);
		//0123456789abcdef
	if ((p % 16) < 10)
	// 16'yla modu rakamsa (0-9)
		i += ft_putchar((p % 16) + '0');
	else
	// diğer durumlarda (10-15) arası için yani abcdef için 87 ekliyoruz ki denk gelsin
		i += ft_putchar((p % 16) - 10 + 'a');
	return (i);
}
// hex integer 
int	ft_x(unsigned int x, int b)
{
	int	i;

	i = 0;
	if (x >= 16)
		i += ft_x(x / 16, b);
	if ((x % 16) < 10)
		i += ft_putchar((x % 16) + '0');
	else
	{
		if (b == 0)
			i += ft_putchar((x % 16) - 10 + 'a');
		else
			i += ft_putchar((x % 16) - 10 + 'A');
	}
	return (i);
}
