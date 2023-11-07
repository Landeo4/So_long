/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:43:31 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/11/07 18:24:45 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[], char *env[])
{
	char	**map;
	t_game	*ptr;
	(void)argc;

	map = map_manager(argv, env);
	if (verif_map_manager(map) != 1)
	{
		free_db_tab(map);
		return (0);
	}
	/*if (verif_size_img(map, ptr) == -1)
	{
		verifier la size des images
		free_db_tab(map);
		ft_printf("wrong tile size\n");
		return (0);
	}*/
	ptr = malloc(sizeof(t_game));
	ptr = init_struct(ptr);
	/*if (game_manager(map, ptr) == -1)
	{
		free_db_tab(map);
		return (-1);
	}
	ft_printf("ptr %d ptr %d\n", ptr->p_y, ptr->p_x);
	game_start(map, ptr);*/
	show_db_tab(map);
	free_struct(ptr);
	free_db_tab(map);
	return (0);
	/*if (!buff)
	{
		while (buff[i])
		{
			ft_printf("%s", buff[i]);
			i++;
		}
		return (write(1, "ERROR\n", 7), -1);
	}*/
	//parsing(argv);
}

void	free_struct(t_game *ptr)
{
	free(ptr->mlx);
	free(ptr->win);
}

t_game	*init_struct(t_game *ptr)
{
	void	*mlx;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	ptr->i = 0;
	ptr->cpt = 0;
	ptr->x = 0;
	ptr->y = 0;
	ptr->nb_item = 0;
	ptr->nb_exit = 0;
	ptr->p_x = 0;
	ptr->p_y = 0;
	ptr->p_mov = 0;
	ptr->img_0 = mlx_xpm_file_to_image(mlx, "tiles/Wall.xpm", &img_width, &img_height);
	ptr->img_1 = mlx_xpm_file_to_image(mlx, "tiles/floor.xpm", &img_width, &img_height);
	ptr->img_2 = mlx_xpm_file_to_image(mlx, "tiles/player.xpm", &img_width, &img_height);
	ptr->img_3 = mlx_xpm_file_to_image(mlx, "tiles/exit.xpm", &img_width, &img_height);
	ptr->img_4 = mlx_xpm_file_to_image(mlx, "tiles/item.xpm", &img_width, &img_height);
	return (ptr);
}

void	show_db_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("la map\n");
	while (map[i])
	{
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
		j = 0;
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
