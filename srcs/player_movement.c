/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:01:28 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 12:48:48 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(t_game *ptr, int input)
{
	int	x;
	int	y;

	y = ptr->p_y;
	x = ptr->p_x;
	if (input == 1)
		y = y -1;
	else if (input == 2)
		x = x - 1;
	else if (input == 3)
		y = y + 1;
	else if (input == 4)
		x = x + 1;
	player_movement_support(ptr, y, x);
}

void	player_movement_support(t_game *ptr, int y, int x)
{
	if (ptr->map[y][x] == ptr->map[ptr->exit_y][ptr->exit_x] && ptr->nb_item == 0)
	{
		close_windows_esc(ptr);
		return ;
	}
	else if (ptr->map[y][x] == 'E')
		ptr->exit = 0;
	else if (ptr->map[y][x] == 'C')
		ptr->nb_item--;
	if (ptr->nb_item == 0)
	{
		//set_pos_exit(ptr, ptr->map);
		ft_printf("as %d %d\n", ptr->exit_y, ptr->exit_x);
		put_image(ptr, &ptr->exit_y, &ptr->exit_x);
	}
	if (ptr->exit == 0)
	{
		ptr->exit = 1;
		ft_printf("y = %d x = %d\n", ptr->exit_y, ptr->exit_x);
		put_image(ptr, &ptr->exit_y, &ptr->exit_x);
	}
	ptr->map[ptr->p_y][ptr->p_x] = '0';
	put_image(ptr, &ptr->p_y, &ptr->p_x);
	ptr->p_y = y;
	ptr->p_x = x;
	ptr->map[ptr->p_y][ptr->p_x] = 'P';
	put_image(ptr, &ptr->p_y, &ptr->p_x);
	ptr->mov++;
	ft_printf("%d\n", ptr->mov);
}
