/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:45:59 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 15:47:38 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	find_ennemi(int keycode, t_map *data)
{
	int	x;
	int	y;

	x = data->pos_x;
	y = data->pos_y;
	if (keycode == XK_w)
		if (data->map[x - 1][y] == 'Z')
			return (1);
	if (keycode == XK_s)
		if (data->map[x + 1][y] == 'Z')
			return (1);
	if (keycode == XK_a)
		if (data->map[x][y - 1] == 'Z')
			return (1);
	if (keycode == XK_d)
		if (data->map[x][y + 1] == 'Z')
			return (1);
	return (0);
}

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
	{	
		if (data->map[data->pos_x][data->pos_y] == 'E')
		{
			ft_printf("CONGRATULATIONS ! YOU WON IN %d MOVES\n", data->moves);
			mlx_loop_end(data->mlx_ptr);
		}
	}
	display_number(data);
	return (0);
}
