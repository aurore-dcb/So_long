/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:45:59 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 10:29:08 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	key_hook(int keycode, t_map *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	else if (keycode == XK_w || keycode == XK_s || keycode == XK_a
		|| keycode == XK_d)
	{
		if (modif_pos(keycode, data))
			display_map(data);
		if (data->map[data->pos_x][data->pos_y] == 'C')
			data->map[data->pos_x][data->pos_y] = '0';
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
