/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:17:48 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 15:15:26 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	display_number(t_map *data)
{
	int		x;
	int		y;
	char	*str_number;

	x = 15;
	y = 30;
	str_number = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x - 1, y - 1, 0xFFFFFF,
		str_number);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x + 1, y - 1, 0xFFFFFF,
		str_number);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x - 1, y + 1, 0xFFFFFF,
		str_number);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x + 1, y + 1, 0xFFFFFF,
		str_number);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000, str_number);
	free(str_number);
}

void	display_map2(t_map *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_w, j
			* 64, i * 64);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_e, j
			* 64, i * 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_c, j
			* 64, i * 64);
	else if (data->map[i][j] == 'Z')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_z, j
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
			if (i != data->pos_x || j != data->pos_y)
				display_map2(data, i, j);
			else
			{
				if (data->right == 1)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img_p_right, j * 64, i * 64);
				else
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img_p_left, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
	return (1);
}
