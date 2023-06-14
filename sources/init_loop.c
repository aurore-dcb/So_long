/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:13:44 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 11:38:52 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	load_img(t_map *data)
{
	int	w;

	data->img_p_left = NULL;
	data->img_p_right = NULL;
	data->img_c = NULL;
	data->img_f = NULL;
	data->img_w = NULL;
	data->img_e = NULL;
	data->img_p_left = mlx_xpm_file_to_image(data->mlx_ptr, "./img/p_left.xpm",
			&w, &w);
	data->img_p_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/p_right.xpm", &w, &w);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, "./img/c.xpm", &w, &w);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, "./img/w.xpm", &w, &w);
	data->img_f = mlx_xpm_file_to_image(data->mlx_ptr, "./img/f.xpm", &w, &w);
	data->img_e = mlx_xpm_file_to_image(data->mlx_ptr, "./img/e.xpm", &w, &w);
	if (!data->img_p_left || !data->img_p_right || !data->img_c || !data->img_w
		|| !data->img_f || !data->img_e)
		return (0);
	return (1);
}

int	modif_pos2(char c, int k, t_map *data)
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
		{
			data->pos_y++;
			data->right = 1;
		}
		else if (k < 0)
		{
			data->pos_y--;
			data->right = 0;
		}
	}
	data->moves++;
	return (1);
}

int	modif_pos(int keycode, t_map *data)
{
	if (keycode == 119)
		if (data->map[data->pos_x - 1][data->pos_y] != '1')
			modif_pos2('x', -1, data);
	if (keycode == 115)
		if (data->map[data->pos_x + 1][data->pos_y] != '1')
			modif_pos2('x', 1, data);
	if (keycode == 97)
		if (data->map[data->pos_x][data->pos_y - 1] != '1')
			return (modif_pos2('y', -1, data));
	if (keycode == 100)
		if (data->map[data->pos_x][data->pos_y + 1] != '1')
			return (modif_pos2('y', 1, data));
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
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->moves = 0;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height,
			"So_long");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr));
	if (load_img(data) == 0)
	{
		ft_printf("Error\nImage not load\n");
		return ;
	}
	data->pos_x = find_x(data->map);
	data->pos_y = find_y(data->map);
	display_map(data);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}
