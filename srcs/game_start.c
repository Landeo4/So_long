/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:03 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 07:37:59 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_start(t_game *ptr)
{
	// mlx_mouse_hook(ptr->win, close_windows_mouse, &ptr);
	mlx_hook(ptr->win, 17, 0, mouse_hook, ptr);
	mlx_key_hook(ptr->win, get_key_hook, ptr);
	// mlx_mouse_hook(ptr->win, tes, ptr);
	mlx_loop(ptr->mlx);
	return (0);
}

int	create_map(t_game *ptr)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = 0;
	height = ft_len_db_tab(ptr->map);
	width = ft_strlen(ptr->map[i]);
	ptr->win = mlx_new_window(ptr->mlx, ((width) * 32),
		((height) * 32), "Hello world!");
	if (ptr->win == NULL)
		return (-1);
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if (put_image(ptr, &i, &j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	put_image(t_game *ptr, int *i, int *j)
{
	if (!ptr->img_0 || !ptr->img_1 || !ptr->img_2
		||!ptr->img_3 || !ptr->img_4)
		return (-1);
	if (ptr->map[*i] && ptr->map[*i][*j] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_0,
			(*j) * 32, (*i) * 32);
	else if (ptr->map[*i] && ptr->map[*i][*j] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_1,
			(*j) * 32, (*i) * 32);
	else if (ptr->map[*i] && ptr->map[*i][*j] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_2,
			(*j) * 32, (*i) * 32);
	else if (ptr->map[*i] && ptr->map[*i][*j] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_3,
			(*j) * 32, (*i) * 32);
	else if (ptr->map[*i] && ptr->map[*i][*j] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_4,
			(*j) * 32, (*i) * 32);
	return (0);
}

int	mouse_hook(t_game *ptr)
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
	exit (0);
}
