/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:13:44 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/02 16:56:49 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int key_hook(int keycode, void *param)
{
	if (keycode == 65307)
	{
		void *win_ptr = param;
    	void *mlx_ptr = mlx_get_data_addr(win_ptr, NULL, NULL, NULL);
		mlx_destroy_window(mlx_ptr, win_ptr);
	}
    return 0;
}

int close_window(void *param)
{
	void *win_ptr = param;
    void *mlx_ptr = mlx_get_data_addr(win_ptr, NULL, NULL, NULL);
	mlx_destroy_window(mlx_ptr, win_ptr);
	return 0;
}

int	load_img(t_map *data)
{
	int	w;

	data->img_p = NULL;
	data->img_c = NULL;
	data->img_f = NULL;
	data->img_w = NULL;
	data->img_e = NULL;
	data->img_p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/sport_car.xpm", &w, &w);
	if (!data->img_p)
		return (ft_printf("p\n"), 0);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, "./images/gas_bottle.xpm", &w, &w);
	if (!data->img_c)
		return (ft_printf("c\n"), 0);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, "./images/roue.xpm", &w, &w);
	if (!data->img_w)
		return (ft_printf("w\n"), 0);
	data->img_f = mlx_xpm_file_to_image(data->mlx_ptr, "./images/back_gray.xpm", &w, &w);
	if (!data->img_f)
		return (ft_printf("f\n"), 0);
	data->img_e = mlx_xpm_file_to_image(data->mlx_ptr, "./images/damier.xpm", &w, &w);
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
	elem->next = NULL;
	elem->x = x;
	elem->y = y;
	elem->active = 1;
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

int loop(t_map *data, char **map)
{
	t_item *lst;
	
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, "So_long");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr), 0);
	if (load_img(data) == 0)
		return (ft_printf("error image\n"), 0);
	lst_item(map, &lst);
	if (!map)
		return (ft_printf("Error lst_item\n"), 0);
	data->pos_x = findX(map);
	data->pos_y = findY(map);
	ft_printf("j = %d\ni = %d\n", lst->y, lst->x);
	display_map(data, map, &lst);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data->win_ptr);  // "ESC" pour fermer 
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data->win_ptr); // Croix pour fermer
    mlx_loop(data->mlx_ptr); // boucle affichage fenetre
	return (1);
}
