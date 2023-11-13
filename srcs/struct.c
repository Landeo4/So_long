/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:28:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 09:52:06 by tpotilli         ###   ########.fr       */
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
	mlx_destroy_image(ptr->mlx, ptr->img_0);
	mlx_destroy_image(ptr->mlx, ptr->img_1);
	mlx_destroy_image(ptr->mlx, ptr->img_2);
	mlx_destroy_image(ptr->mlx, ptr->img_3);
	mlx_destroy_image(ptr->mlx, ptr->img_4);
	return ;
}

void	init_struct(t_game *ptr, char **map)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->nb_item = nb_item(map);
	ptr->nb_exit = nb_exit(map);
	ptr->nb_player = nb_player(map);
	ptr->p_x = 0;
	ptr->p_y = 0;
	ptr->p_mov = 0;
	ptr->map = NULL;
	ptr->mov = 0;
	set_pos_exit(ptr, map);
}

void	set_pos_exit(t_game *ptr, char **map)
{
	int	i;
	int	j;

	i = ((j = 0));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				ptr->p_x_exit = ptr->x;
				ptr->p_y_exit = ptr->y;
				return ;
			}
			j++;
		}
		i++;
	}
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
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	len++;
	ptr->map = malloc(sizeof(char *) * (len + 1));
	while (map[i])
	{
		j = 0;
		ptr->map[i] = malloc(sizeof(char) * (len + 1));
		while (map[i][j])
		{
			ptr->map[i][j] = map[i][j];
			j++;
		}
		ptr->map[i][j] = '\0';
		i++;
	}
	ptr->map[i] = '\0';
	free_db_tab(map);
}
