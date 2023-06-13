/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:45:59 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 14:14:12 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	key_hook(int keycode, t_map *param)
{
	if (keycode == XK_Escape)
		mlx_loop_end(param->mlx_ptr);
	else if (keycode == 119 || keycode == 115 || keycode == 97
		|| keycode == 100)
	{
		if (modif_pos(keycode, param))
			display_map(param);
		if (param->map[param->pos_x][param->pos_y] == 'C')
			param->map[param->pos_x][param->pos_y] = '0';
	}
	return (1);
}

int	loop_hook(t_map *data)
{
	if (!still_collectible(data))
		if (data->map[data->pos_x][data->pos_y] == 'E')
			mlx_loop_end(data->mlx_ptr);
	display_number(data);
	return (0);
}
