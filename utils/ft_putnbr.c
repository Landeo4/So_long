/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:48:52 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/10/23 14:08:33 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(int nbr)
{
	int	cpt;

	cpt = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		cpt++;
	}
	return (cpt);
}

int	ft_u_count(unsigned int nbr)
{
	int	cpt;

	cpt = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		cpt++;
	}
	return (cpt);
}

int	ft_putnbr(int nbr)
{
	int		cpt;
	char	*num;

	cpt = 0;
	num = ft_itoa(nbr);
	cpt = ft_putstr(num);
	free(num);
	return (cpt);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_u_count(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		cpt;
	char	*num;

	cpt = 0;
	if (n == 0)
		cpt += write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(n);
		cpt += ft_putstr(num);
		free(num);
	}
	return (cpt);
}

/*int main()
{
	printf("%d", ft_putnbr(465, 0));
}*/