/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:18:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 08:35:18 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_manager(char **map, t_game *ptr)
{
	int		x;
	int		y;
	char	**tmp;

	player_pos(map, ptr);
	if (ptr->p_x == -1)
		return (-1);
	tmp = cpy_map(map);
	if (!tmp)
		return (-1);
	x = ptr->p_x;
	y = ptr->p_y;
	if (game_backtracking(tmp, ptr, y, x) == -1)
		return (free_db_tab(tmp), -1);
	free_db_tab(tmp);
	return (0);
}

int	get_len_map(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1')
				len++;
			j++;
		}
		i++;
		j = 0;
	}
	return (len);
}

int	nb_item(char **map)
{
	int	i;
	int	j;
	int	item;

	i = 0;
	j = 0;
	item = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
			if (map[i][j] == 'C')
				item++;
		}
		i++;
		j = 0;
	}
	return (item);
}
