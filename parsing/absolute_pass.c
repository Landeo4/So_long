/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_pass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:59:39 by tpotillion        #+#    #+#             */
/*   Updated: 2023/11/09 10:32:59 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_absolute_pass(char **argv)
{
    int		i;
    int		j;
	int		c;
    char	*name;
	int		token;

    i = ((j = 0));
	c = ((token = 0));
    while(argv[i])
        i++;
    i--;
    while (argv[i][j])
    {
		if (argv[i][j] == '/')
			token++;
        j++;
    }
	if (token == 0)
		return (0);
    else
		verif_pass_ber(argv, i, j, c);
    return (1);
}

int	verif_pass_ber(char **argv)
{
	int	c;

	c = 0;
	j = j - 4;
	name = ".ber";
    while (argv[i][j])
    {
        if (argv[i][j] != name[c])
			return (-1);
		j++;
		c++;
    }
}
