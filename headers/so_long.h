/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:37 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 09:39:36 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
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

typedef struct s_item
{
	int				x;
	int				y;
	int active; // 1 = pas ramasse ; 0 = ramasse
	struct s_item	*next;
}					t_item;

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
	void			*img_p;
	void			*img_w;

	int				pos_x;
	int				pos_y;
	t_item			*item;
	int				moves;
}					t_map;

// parsing2.c
int					extension(char *s);
int					is_rectangle(t_lign **begin);
int					composition(t_lign **begin);
int					five_char(t_lign **begin);
int					walls(t_lign **begin);

// parsing.c
int					verifs(char *file, t_lign **list);
int					parsing(int argc, char **argv, t_lign **list);

// utils.c
char				*ft_strdup_trim(char *src);
void				free_list(t_lign **begin);
void				free_tab(char **tab);
int					ft_lstsize(t_lign *lst);

// create_list.c
int					item_in_lign(char c, char *str);
t_lign				*ft_new_elem(char *str);
int					ft_list_push_back(t_lign **begin, char *lign);
int					create_list(t_lign **list, char *file);
void				display_list(t_lign *begin);

// list_to_tab.c
char				**list_to_tab(t_lign **begin);
void				display_tab(char **map);

// check_path.c
void				cross_map(char **map);
int					valid_path(char **map);

// init_loop.c
// int					key_hook(int keycode, void *param);
int					close_window(void *param);
int					still_collectible(t_map *data);
int					loop(t_map *data);
void				display_list_item(t_item *begin);

// display_map.c
int					display_map(t_map *data);

// main.c
int					findX(char **map);
int					findY(char **map);

#endif
