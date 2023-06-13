/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:13:44 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 10:07:11 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	close_window(void *param)
{
	void	*win_ptr;
	void	*mlx_ptr;

	win_ptr = param;
	mlx_ptr = mlx_get_data_addr(win_ptr, NULL, NULL, NULL);
	mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}

int	load_img(t_map *data)
{
	int	w;

	data->img_p = NULL;
	data->img_c = NULL;
	data->img_f = NULL;
	data->img_w = NULL;
	data->img_e = NULL;
	data->img_p = mlx_xpm_file_to_image(data->mlx_ptr, "./img/p.xpm", &w, &w);
	if (!data->img_p)
		return (ft_printf("p\n"), 0);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, "./img/c.xpm", &w, &w);
	if (!data->img_c)
		return (ft_printf("c\n"), 0);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, "./img/w.xpm", &w, &w);
	if (!data->img_w)
		return (ft_printf("w\n"), 0);
	data->img_f = mlx_xpm_file_to_image(data->mlx_ptr, "./img/f.xpm", &w, &w);
	if (!data->img_f)
		return (ft_printf("f\n"), 0);
	data->img_e = mlx_xpm_file_to_image(data->mlx_ptr, "./img/e.xpm", &w, &w);
	if (!data->img_e)
		return (ft_printf("e\n"), 0);
	return (1);
}

t_item	*ft_lstnew(int x, int y)
{
	t_item	*elem;

	elem = malloc(sizeof(t_item));
	if (!elem)
		return (NULL);
	elem->x = x;
	elem->y = y;
	elem->active = 1;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back(t_item **lst, t_item *new)
{
	t_item	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*lst = new;
}

void lst_item(char **map, t_item **lst)
{
	int i;
	int j;
	t_item *new;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				new = ft_lstnew(j, i);
				if (!new)
					return ; // +fct free lst
				// ft_printf("j = %d\ni = %d\n", new->y, new->x);
				ft_lstadd_back(lst, new);
			}
			j++;
		}
		i++;
	}
}


// void	display_list_item(t_item *begin)
// {
// 	t_item	*list;

// 	list = begin;
// 	if (list)
// 	{
// 		while (list)
// 		{
// 			ft_printf("x : %d\n", list->x);
// 			ft_printf("y : %d\n", list->y);
// 			ft_printf("acive : %d\n", list->active);
// 			list = list->next;
// 		}
// 	}
// }

void modif_pos2(char c, int k, t_map *data)
{
	if (c == 'x')
	{
		if (k > 0)
			data->pos_x++;
		else if (k < 0)
			data->pos_x--;
	}
	else if (c == 'y')
	{
		if (k > 0)
			data->pos_y++;
		else if (k < 0)
			data->pos_y--;
	}
	data->moves++;
	ft_printf("moves = %d\n", data->moves);
}
void modif_pos(int keycode, t_map *param)
{
	int x;
	int y;
	
	y = param->pos_y;
	x = param->pos_x;
	if (keycode == 119)
		if (param->map[x - 1][y] != '1')
			modif_pos2('x', -1, param);	
	if (keycode == 115)
		if (param->map[x + 1][y] != '1')
			modif_pos2('x', 1, param);	
	if (keycode == 97)
		if (param->map[x][y - 1] != '1')
			modif_pos2('y', -1, param);	
	if (keycode == 100)
		if (param->map[x][y + 1] != '1')
			modif_pos2('y', 1, param);	
}

int	key_hook(int keycode, t_map *param)
{
	void	*win_ptr;
	void	*mlx_ptr;
	
	if (keycode == 65307)
	{
		win_ptr = param->win_ptr;
		mlx_ptr = mlx_get_data_addr(win_ptr, NULL, NULL, NULL);
		mlx_destroy_window(mlx_ptr, win_ptr);
	}
	else if (keycode == 119 || keycode == 115 || keycode == 97
			|| keycode == 100)
	{
		modif_pos(keycode, param);
		if (param->map[param->pos_x][param->pos_y] == 'C')
			param->map[param->pos_x][param->pos_y] = '0';
	}
	return (0);
}

int still_collectible(t_map *data)
{
	int i;
	int j;

	i = 1;
	while (data->map[i])
	{
		j = 1;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	loop_hook(t_map *data)
{
	if (!still_collectible(data))
		if (data->map[data->pos_x][data->pos_y] == 'E')
			close_window(data->win_ptr);
	display_map(data); // Afficher la map
	return (0);
}

int	loop(t_map *data)
{
	data->moves = 0;
	data->item = NULL;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height,
			"So_long");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr), 0);
	if (load_img(data) == 0)
		return (ft_printf("error image\n"), 0);
	lst_item(data->map, &data->item);
	if (!data->map)
		return (ft_printf("Error lst_item\n"), 0);
	data->pos_x = findX(data->map);
	data->pos_y = findY(data->map);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data); // "ESC" pour fermer
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data); // Croix pour fermer
	mlx_loop(data->mlx_ptr); // boucle affichage fenetre
	return (1);
}
