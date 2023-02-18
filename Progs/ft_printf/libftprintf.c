/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:13:11 by lray              #+#    #+#             */
/*   Updated: 2023/02/18 18:35:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_format(va_list args, const char flag);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
			len += ft_format(args, str[i++ + 1]);
		i++;
	}
	va_end(args);
	return (len);
}

static int	ft_format(va_list args, const char flag)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		len += ft_putptr(va_arg(args, uintptr_t));
	else if (flag == 'd' || flag == 'i')
		len += ft_put10(va_arg(args, int));
	else if (flag == 'u')
		len += ft_putu10(va_arg(args, unsigned int));
	else if (flag == 'x')
		len += ft_put16(va_arg(args, unsigned int), HEX_LOW);
	else if (flag == 'X')
		len += ft_put16(va_arg(args, unsigned int), HEX_UP);
	else if (flag == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}
