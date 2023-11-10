/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:28:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/10 14:46:52 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct(t_game *ptr)
{
	int	i;

	i = 0;
	while (ptr->map[i])
	{
		free(ptr->map[i]);
		i++;
	}
	free(ptr->map);
	free(ptr->mlx);
	free(ptr->win);
	free(ptr->img_0);
	free(ptr->img_1);
	free(ptr->img_2);
	free(ptr->img_3);
	free(ptr->img_4);
	return ;
}

void	init_struct(t_game *ptr, char **map)
{
	second_init_struct(ptr, ptr->mlx);
	ptr->x = 0;
	ptr->y = 0;
	ptr->nb_item = nb_item(map);
	ptr->nb_exit = nb_exit(map);
	ptr->p_x = 0;
	ptr->p_y = 0;
	ptr->p_mov = 0;
	ptr->map = NULL;
	ptr->mov = 0;
}

void	second_init_struct(t_game *ptr, void *mlx)
{
	int		img_width;
	int		img_height;

	img_height = 32;
	img_width = 32;
	ptr->img_0 = mlx_xpm_file_to_image(mlx,
			"tiles/Wall2.xpm", &img_width, &img_height);
	ptr->img_1 = mlx_xpm_file_to_image(mlx,
			"tiles/floor2.xpm", &img_width, &img_height);
	ptr->img_2 = mlx_xpm_file_to_image(mlx,
			"tiles/Player2.xpm", &img_width, &img_height);
	ptr->img_3 = mlx_xpm_file_to_image(mlx,
			"tiles/exit2.xpm", &img_width, &img_height);
	ptr->img_4 = mlx_xpm_file_to_image(mlx,
			"tiles/item2.xpm", &img_width, &img_height);
}

void	struct_map(char **map, t_game *ptr)
{
	int	i;
	int	j;

	i = 0;
	ptr->map = malloc(sizeof(char *) * (ft_len_db_tab(map) + 1));
	while (map[i])
	{
		j = 0;
		ptr->map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		while (map[i][j])
		{
			ptr->map[i][j] = map[i][j];
			j++;
		}
		ptr->map[i][j] = '\0';
		i++;
	}
	ptr->map[i] = '\0';
}
