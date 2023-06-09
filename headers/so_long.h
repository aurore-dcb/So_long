/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:37 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/15 16:06:48 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_lign
{
	char			*lign;
	int				lign_len;
	int				nb_exit;
	int				nb_pos;
	int				nb_item;
	struct s_lign	*next;
}					t_lign;

typedef struct s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	char			**map;

	void			*img_c;
	void			*img_e;
	void			*img_f;
	void			*img_p_right;
	void			*img_p_left;
	void			*img_w;
	void			*img_z;

	int				pos_x;
	int				pos_y;
	int				moves;
	int				right;
}					t_map;

// frees.c
void				free_list(t_lign **begin);
void				free_tab(char **tab);
void				free_mlx(t_map *data);
void				free_all(t_map *data, t_lign **list);

// parsing2.c
int					extension(char *s);
int					is_rectangle(t_lign **begin);
int					composition(t_lign **begin);
int					six_char(t_lign **begin);
int					walls(t_lign **begin);

// parsing.c
int					verifs(char *file, t_lign **list);
int					parsing(int argc, char **argv, t_lign **list);

// utils.c
int					in_set(char const *set, const char c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strdup_trim(char *src);
int					ft_lstsize(t_lign *lst);

// create_list.c
int					item_in_lign(char c, char *str);
t_lign				*ft_new_elem(char *str);
int					ft_list_push_back(t_lign **begin, char *lign);
int					create_list(t_lign **list, char *file);

// list_to_tab.c
char				**list_to_tab(t_lign **begin);

// check_path.c
int					to_cross(char c);
int					add_cross(char **map, int i, int j);
void				cross_map(char **map);
int					valid_path(char **map);

// display_map.c
void				display_number(t_map *data);
int					display_map(t_map *data);

// hook.c
int					find_ennemi(int keycode, t_map *data);
int					key_hook(int keycode, t_map *data);
int					loop_hook(t_map *data);

// init_loop.c
int					load_img(t_map *data);
int					modif_pos2(char c, int k, t_map *data);
int					modif_pos(int keycode, t_map *data);
int					still_collectible(t_map *data);
void				loop(t_map *data);

// main.c
int					find_x(char **map);
int					find_y(char **map);

#endif
