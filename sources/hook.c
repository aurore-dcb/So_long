/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:45:59 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 12:06:02 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	close_window(t_map *param)
{
	mlx_loop_end(param->mlx_ptr);
	// mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	return (0);
}

int	key_hook(int keycode, t_map *param)
{
	if (keycode == 65307)
	{
		mlx_loop_end(param->mlx_ptr);
		// mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	}
	else if (keycode == 119 || keycode == 115 || keycode == 97
		|| keycode == 100)
	{
		modif_pos(keycode, param);
		if (param->map[param->pos_x][param->pos_y] == 'C')
			param->map[param->pos_x][param->pos_y] = '0';
	}
	return (1);
}

int	loop_hook(t_map *data)
{
	if (!still_collectible(data))
		if (data->map[data->pos_x][data->pos_y] == 'E')
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	display_map(data);
	return (0);
}
