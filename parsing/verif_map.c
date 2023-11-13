/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:40:15 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 07:57:02 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_map_manager(char **map, int fd0, int fd1, int fd2)
{
	int	fd3;
	int	fd4;

	fd3 = open ("tiles/Player2.xpm", O_RDONLY);
	if (fd3 < 0)
		return (-1);
	fd4 = open ("tiles/Wall2.xpm", O_RDONLY);
	if (fd4 < 0)
		return (-1);
	if (verif_regularity(map) == -1)
		return (-1);
	if (verif_map_outline(map) == -1)
		return (pr_error("wrong outline or inside\n"), -1);
	if (verif_size_img(fd0) == -1 || (verif_size_img(fd1) == -1)
		|| (verif_size_img(fd2) == -1) || (verif_size_img(fd3) == -1)
		|| (verif_size_img(fd4) == -1))
		return (pr_error("wrong tile size\n"), -1);
	return (1);
}

int	verif_regularity(char **map)
{
	int	i;
	int	tk;
	int	jt;

	i = 0;
	tk = 0;
	jt = 0;
	while (map[i] && map[i + 1])
	{
		tk = ft_strlen(map[i]);
		jt = ft_strlen(map[i + 1]);
		if (tk != jt)
			return (pr_error("map is not regular\n"), -1);
		i++;
	}
	return (0);
}

int	verif_map_outline(char **map)
{
	if (map_out_help(map) == -1)
		return (-1);
	if (verif_map_middle(map) == -1)
		return (-1);
	return (0);
}

int	verif_map_middle(char **map)
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
