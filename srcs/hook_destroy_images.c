/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_destroy_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:07:13 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/12 08:34:04 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_key_hook(int keycode, t_game *ptr)
{
	ptr->nb_item = nb_item(ptr->map);
	ptr->p_mov = 0;
	if (keycode == 119)
		ptr->p_mov = 1;
	else if (keycode == 97)
		ptr->p_mov = 2;
	else if (keycode == 115)
		ptr->p_mov = 3;
	else if (keycode == 100)
		ptr->p_mov = 4;
	if (keycode == 65307)
	{
		close_windows_esc(ptr);
		exit (0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115
		|| keycode == 100)
	{
		if (try_moove(ptr) == 0)
			player_movement(ptr, ptr->p_mov);
	}
	return (0);
}

int	try_moove(t_game *ptr)
{
	if (ptr->p_mov == 1)
	{
		if (ptr->map[ptr->p_y - 1][ptr->p_x] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 2)
	{
		if (ptr->map[ptr->p_y][ptr->p_x - 1] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 3)
	{
		if (ptr->map[ptr->p_y + 1][ptr->p_x] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 4)
	{
		if (ptr->map[ptr->p_y][ptr->p_x + 1] == '1')
			return (-1);
	}
	return (0);
}

void	close_windows_esc(t_game *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img_0);
	mlx_destroy_image(ptr->mlx, ptr->img_1);
	mlx_destroy_image(ptr->mlx, ptr->img_2);
	mlx_destroy_image(ptr->mlx, ptr->img_3);
	mlx_destroy_image(ptr->mlx, ptr->img_4);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free_db_tab(ptr->map);
	free(ptr->mlx);
	// free(ptr->win);
	exit(0);
}

// int	close_windows_mouse(int keycode, t_game *vars, char **map)
// {
// 	int i;
// 	int j;

// 	if (keycode == 1)
// 	{
// 		i = 0;
// 		while (map[i])
// 		{
// 			j = 0;
// 			while (map[i][j])
// 			{
// 				mlx_destroy_window(vars->mlx, vars->win);
// 				j++;
// 			}
// 			i++;
// 		}
// 		exit(0);
// 	}
// 	printf("Hello from mouse_hook!\n");
// 	return (0);
// }
