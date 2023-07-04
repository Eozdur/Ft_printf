/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:17:09 by eozdur            #+#    #+#             */
/*   Updated: 2023/07/05 01:39:13 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// gelen harfi kontrol ediyoruz
int	ft_format(char c, va_list arg)
{
	int	p;

	p = 0;
	if (c == 'c')
		p += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		p += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		p += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		p += ft_u(va_arg(arg, unsigned int));
	else if (c == 'x')
	// 0 ise küçük
		p += ft_x(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
	// 1 ise büyük
		p += ft_x(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		// başına 0x koy ve pointer adresini yazdır
		p += ft_putstr("0x");
		p += ft_p(va_arg(arg, unsigned long));
	}
	// eğer %% girilmişse putchar ile % yazdır
	else if (c == '%')
		p += ft_putchar('%');
	else
	// diğer durumlarda kendisini döndür
		return (ft_putchar(c));
	return (p);
}
// ...nın amacı sınırsız argüman
int	ft_printf(const char *s, ...)
{
	// variadic fonksiyon oluşturuyoruz
	va_list	arg;
	int		i;
	int		j;
	
	// va_start ile argüman listesi ilklendiriliyor
	va_start(arg, s);
	i = 0;
	j = 0;
	// s bitene kadar
	while (s[i])
	{
		// printf("emre") gibi bir değer gelirse putcharla direk yazdır
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			j++;
		}
		// eğer %'e denk gelirse
		if (s[i] == '%')
		{ 
			i++;
			while (s[i] == ' ' && s[i])
				i++;
				// harfe (d,s,p) denk gelince ft_format fonksiyonuna at
			j += ft_format(s[i], arg);
		}
		i++;
	}
	// va_end ile bitir
	va_end(arg);
	return (j);
}
#include <stdio.h>
int main()
{
	char *dizi="42 Kocaeli";
	ft_printf("%d %s %p %c %x %X %%\n",123,"emre",dizi,'a',2002,2003);
}