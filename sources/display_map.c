/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:17:48 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 11:16:14 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	display_map2(t_map *data, int i, int j)
{
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_e, j
			* 64, i * 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_c, j
			* 64, i * 64);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_f, j
			* 64, i * 64);
}

int	display_map(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_w, j * 64, i * 64);
			else if (i == data->pos_x && j == data->pos_y)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_p, j * 64, i * 64);
			else
				display_map2(data, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
