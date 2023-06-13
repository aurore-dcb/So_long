/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:13:44 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 14:06:49 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

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

int	modif_pos2(char c, int k, t_map *data)
{
	int	w;

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
		{
			data->pos_y++;
			mlx_destroy_image(data->mlx_ptr, data->img_p);
			data->img_p = mlx_xpm_file_to_image(data->mlx_ptr, "./img/p.xpm",
					&w, &w);
			if (!data->img_p)
				return (ft_printf("p\n", 0));
		}
		else if (k < 0)
			data->pos_y--;
	}
	data->moves++;
	return (ft_printf("total moves = %d\n", data->moves), 1);
}

int	modif_pos(int keycode, t_map *param)
{
	int	w;

	if (keycode == 119)
		if (param->map[param->pos_x - 1][param->pos_y] != '1')
			modif_pos2('x', -1, param);
	if (keycode == 115)
		if (param->map[param->pos_x + 1][param->pos_y] != '1')
			modif_pos2('x', 1, param);
	if (keycode == 97)
	{
		if (param->map[param->pos_x][param->pos_y - 1] != '1')
		{
			mlx_destroy_image(param->mlx_ptr, param->img_p);
			param->img_p = mlx_xpm_file_to_image(param->mlx_ptr,
					"./img/p_left.xpm", &w, &w);
			if (!param->img_p)
				return (ft_printf("p\n", 0));
			return (modif_pos2('y', -1, param));
		}
	}
	if (keycode == 100)
		if (param->map[param->pos_x][param->pos_y + 1] != '1')
			return (modif_pos2('y', 1, param));
	return (1);
}

int	still_collectible(t_map *data)
{
	int	i;
	int	j;

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

void	loop(t_map *data)
{
	data->moves = 0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height,
			"So_long");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr));
	if (load_img(data) == 0)
	{
		ft_printf("error image\n");
		return ;
	}
	data->pos_x = find_x(data->map);
	data->pos_y = find_y(data->map);
	display_map(data);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}
