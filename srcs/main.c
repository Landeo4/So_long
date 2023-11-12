/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:43:31 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/11/12 09:17:19 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[], char *env[])
{
	char	**map;
	t_game	ptr;
	(void)argc;

	map = map_manager(argv, env);
	if (map == NULL)
		return (free(map), -1);
	init_struct(&ptr, map);
	if (verif_all(map, &ptr) == -1)
		return (free_db_tab(map), 0);
	ptr.mlx = mlx_init();
	if (!ptr.mlx)
		return (-1);
	second_init_struct(&ptr, ptr.mlx);
	struct_map(map, &ptr);
	game_start(&ptr);
	return (0);
}

int	verif_all(char **map, t_game *ptr)
{
	if (ptr->nb_exit != 1 || ptr->nb_player != 1)
		return (pr_error("invalid number of exit or player\n"), -1);
	if (verif_map_manager(map) != 1)
		return (-1);
	if (game_manager(map, ptr) == -1)
		return (-1);
	// if (verif_size_img(map, ptr) == -1)
	// {
	// 	free_db_tab(map);
	// 	ft_printf("wrong tile size\n");
	// 	return (0);
	// }
	return (0);
}

void	show_db_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("la map\n");
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return ;
}

void	free_db_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}
