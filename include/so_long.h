/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:33 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/11/07 17:22:52 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

/*
=====================================
			STRUCTURE
=====================================
*/

typedef struct s_game
{
	int		i;
	int 	cpt;
	int 	x;
	int 	y;
	int		nb_item;
	int		nb_exit;
	int 	p_x;
	int 	p_y;
	int		p_mov;
	void	*mlx;
	void	*win;
	char	*img_0;
	char	*img_1;
	char	*img_2;
	char	*img_3;
	char	*img_4;
	int		width;
	int		height;
}		t_game;

int		ft_strlen(char *s);
int		main(int argc, char *argv[], char *env[]);
int		pr_error(char *error);
int		game_manager(char **map, t_game *ptr);
t_game	*player_pos(char **map, t_game *ptr);
int		nb_item(char **map);
char	**cpy_map(char **map);
t_game	*init_struct(t_game *ptr);
void	show_db_tab(char **map);
void	free_db_tab(char **map);
int		get_len_map(char **map);
int		game_backtracking(char **tmp, t_game *ptr, int y, int x);
int		backtracking_map(char **tmp, int y, int x);
char	**map_fill(char **tmp, int y, int x, t_game *ptr);
int		backtracking_map_finish(char **tmp);
char	**cpy_map_outline(char **tmp);
int		game_start(char **map, t_game *ptr);
int		create_map(char **map, t_game *ptr);
int		put_image(char **map, t_game *ptr, int *i, int *j);
void	player_movement(char **map, t_game *ptr);
void	free_all(t_game *ptr);
void	close_windows_esc(t_game *vars, char **map);
int		close_windows_mouse(int keycode, t_game *vars, char **map);
int		get_keycode(int keycode, t_game *vars, char **map);
int		try_moove(char **map, t_game *ptr);
void	free_struct(t_game *ptr);

/*
=====================================
			PARSING
=====================================
*/

bool	parsing(char *argv[]);
int		verif_map_outline(char **map);
int		verif_map(char **argv);
char	**map_manager(char *argv[], char *evp[]);
char	*ft_get_path(char **env);
int		get_lenght(char *tmp, char *argv[]);
char	*get_final_path_map(char *argv[], char *tmp);
char	*get_perfect_pass(char *tmp);
char	**get_map(char *tmp);

/*
=====================================
			MAP VERIF
=====================================
*/
int		verif_map_manager(char **map);
int		map_out_help(char **map);
int		verif_map_middle(char **map, int i, int tk_f, int tk_l);
int		verif_square(char **map);
int		verif_playable(char **map);

/*
=====================================
			GET_NEXT_LINE
=====================================
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*ft_first_backup(char *backup, int fd);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_cpy(char *s1, char *s2, char *str);
char		*ft_str(char *backup);
char		*ft_clean(char *backup, int i);
char		*free_join(char *backup, char *buffer);
char		*ft_substr(char *s, int start, int len);
int			ft_find_newline(char *str);

/*
=====================================
			PRINTF et LIBFT
=====================================
*/

int					ft_putchar(char c);
void				ft_putnbr_base(unsigned int nbr, const char format);
int					ft_putstr(char *s);
int					ft_putnbr(int nbr);
int					ft_printf(const char *str, ...);
int					ft_count_base(unsigned int nbr);
int					ft_count(int nbr);
int					ft_putnbr_unsigned(unsigned int nbr);
int					ft_unsigned_count(unsigned int nbr);
int					ft_count_help(unsigned long long nbr, int cpt);
int					ft_ptr_len(uintptr_t num);
void				ft_put_ptr(uintptr_t num);
int					ft_print_ptr(unsigned long long ptr);
char				*ft_itoa(int n);
int					ft_print_hex(unsigned int nbr, const char format);
int					ft_strlen(char *str);
int					ft_letter(char const *s, char c, int i);
char				**ft_free(char **split, int index_word);
int					ft_word(char const *s, char c);
char				**ft_copy(char const *s, char c, char **split, int i);
char				**ft_split(char const *s, char c);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*str_join_free(char *path, char *cmd);
char				*ft_cpyjoin(char const *s1, char const *s2, char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strlcpy(char *dest, const char *src, int size);
char				*copy_char(char *s1, char *s2, int i, int j);
char				*ft_strdup(char *s);
int					ft_len_db_tab(char **str);

#endif