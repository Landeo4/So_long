/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:49:00 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/10/23 14:08:27 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_base(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, format);
		ft_putnbr_base(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
		{
			if (format == 'x')
				ft_putchar((nbr - 10) + 'a');
			else if (format == 'X')
				ft_putchar((nbr - 10) + 'A');
		}
	}
}

int	ft_count_base(unsigned int nbr)
{
	int	cpt;

	cpt = 0;
	while (nbr > 0)
	{
		cpt++;
		nbr = nbr / 16;
	}
	return (cpt);
}

int	ft_print_hex(unsigned int nbr, const char format)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_putnbr_base(nbr, format);
	return (ft_count_base(nbr));
}
