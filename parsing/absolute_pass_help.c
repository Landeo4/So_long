/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_pass_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:28:59 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 16:56:42 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_characters(char **split)
{
	int	i;
	int	j;
	int	cpt;

	i = ((cpt = 0));
	j = 0;
	while (split[0][j])
	{
		cpt++;
		j++;
	}
	ft_printf("j = %d\n", j);
	j = 0;
	if (verif_else(split, i, j, cpt) == -1)
		return (-1);
	return (0);
}

int	verif_else(char **split, int i, int j, int cpt)
{
	if (split[i] == NULL)
		return (-1);
	ft_printf("cpt = %d\n", cpt);
	ft_printf("%s\n", split[i]);
	if (split[i][cpt] == 1)
		return (0);
	if (cpt != 0)
		return (-1);
	ft_printf("j = %d\n", j);
	return (0);
}
