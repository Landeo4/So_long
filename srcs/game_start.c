/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:03 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/08 14:19:03 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_start(t_game *ptr)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		return (-1);
	create_map(ptr);
	// mlx_mouse_hook(ptr->win, close_windows_mouse, &ptr);
	mlx_hook(ptr->win, 2, 1L << 0, get_keycode, &ptr);
	//player_movement(map, ptr);
	mlx_loop(ptr->mlx);
	return (0);
}

int create_map(t_game *ptr)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = 0;
	height = ft_len_db_tab(ptr->map);
	width = ft_strlen(ptr->map[i]);
	ptr->win = mlx_new_window(ptr->mlx, ((width) * 16), 
	((height) * 16), "Hello world!");
	// ptr->win = mlx_new_window(ptr->mlx, 500, 500, "Hello world!");
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
	if (ptr->map[*i] && ptr->map[*i][*j] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_0,
		(*j) * 16, (*i) * 16);
	else if (ptr->map[*i] && ptr->map[*i][*j] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_1,
		(*j) * 16, (*i) * 16);
	else if (ptr->map[*i] && ptr->map[*i][*j] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_2,
		(*j) * 16, (*i) * 16);
	else if (ptr->map[*i] && ptr->map[*i][*j] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_3,
		(*j) * 16, (*i) * 16);
	else if (ptr->map[*i] && ptr->map[*i][*j] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_4,
		(*j) * 16, (*i) * 16);
	return (0);
}

/*void player_movement(char **map, t_game *ptr)
{
	int		y;
	int		x;

	mlx_key_hook(ptr->win, key_hook, &ptr);
	if ()
}*/
