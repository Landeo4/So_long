/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:47:58 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/10/23 14:08:22 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check(va_list args, const char format)
{
	int	cpt;

	cpt = 0;
	if (format == 'c')
		cpt += ft_putchar(va_arg(args, int));
	else if (format == 's')
		cpt += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		cpt += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		cpt += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		cpt += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		cpt += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		cpt += ft_putchar('%');
	return (cpt);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cpt;
	va_list	args;

	i = 0;
	cpt = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			cpt += ft_check(args, str[i + 1]);
			i++;
		}
		else
			cpt += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (cpt);
}
