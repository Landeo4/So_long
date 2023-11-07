/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:18:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/07 18:18:51 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_manager(char **map, t_game *ptr)
{
	int		x;
	int		y;
	char	**tmp;

	ptr->nb_item = nb_item(map);
	ptr = player_pos(map, ptr);
	if (ptr->p_x == -1)
		return (-1);
	tmp = cpy_map(map);
	show_db_tab(tmp);
	x = ptr->p_x;
	y = ptr->p_y;
	if (game_backtracking(tmp, ptr, y, x) == -1)
	{
		ft_printf("wrong map\n");
		return (-1);
	}
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

t_game	*player_pos(char **map, t_game *ptr)
{
	int		i;
	int		j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				ptr->p_x = j;
				ptr->p_y = i;
				return (ptr);
			}
			j++;
		}
		i++;
	}
	ptr->p_x = -1;
	return (ptr);
}

char	**cpy_map(char **map)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	i = 0;
	len = 0;
	while (map[i])
	{
		i++;
		len++;
	}
	i = 0;
	tmp = malloc(sizeof (char *) * (len + 1));
	if (!tmp)
		return (NULL);
	while (map[i] && map[i])
	{
		tmp[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!tmp[i])
			return (NULL);
		j = 0;
		while (map[i][j])
		{
			tmp[i][j] = map[i][j];
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

/*
char **cpy_map(char **map)
{
	int		i;
	int		x;
	int		j;
	int		len;
	char	**tmp;

	i = 1;
	x = 0;
	len = 0;
	while (map[i + 1])
	{
		i++;
		len++;
	}
	i = 1;
	tmp = malloc(sizeof (char *) * len);
	if (!tmp)
		return (NULL);
	ft_printf("len %d\n", len);
	while (map[i] && map[i + 1])
	{
		tmp[x] = malloc(sizeof(char) * (ft_strlen(map[i]) - 1));
		if (!tmp[x])
			return (NULL);
		j = 1;
		while (map[i][j] && map[i][j + 1])
		{
			tmp[x][j] = map[i][j];
			j++;
		}
		ft_printf("x %d\n", x);
		tmp[x][j] = '\0';
		i++;
		x++;
	}
	tmp[x] = NULL;
	return (tmp);
}
*/

/*char **map_creator(char **map)
{
	char	**lit_map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	lit_map = malloc(sizeof(char *) * ft_strlen(map[i]));
	while (map[i])
	{
		while (map[i][j])
		{
			lit_map[i][j] = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (lit_map);
}*/
