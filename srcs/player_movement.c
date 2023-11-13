/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:01:28 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 09:51:48 by tpotilli         ###   ########.fr       */
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
	if (ptr->map[y][x] == 'E' && ptr->nb_item == 0)
	{
		close_windows_esc(ptr);
		return ;
	}
	else if (ptr->map[y][x] == 'C')
		ptr->nb_item--;
	ptr->map[ptr->p_y][ptr->p_x] = '0';
	put_image(ptr, &ptr->p_y, &ptr->p_x);
	ptr->p_y = y;
	ptr->p_x = x;
	ptr->map[ptr->p_y][ptr->p_x] = 'P';
	put_image(ptr, &ptr->p_y, &ptr->p_x);
	ptr->mov++;
	if (ptr->p_x_exit != ptr->p_x &&ptr->p_y_exit != ptr->p_y)
		put_image(ptr, &y, &x);
	ft_printf("%d\n", ptr->mov);
}

/*
le joueur peux se deplacer
faire bouger le joueur
augmenter compteur d'item pour debloquer la sortie
augmenter le compteur de mouvement
*/
