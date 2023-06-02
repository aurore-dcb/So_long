/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:17:48 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/02 16:08:56 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void display_map(t_map *data, char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (i == data->pos_y && j == data->pos_x)
            {
                ft_printf("pos\n");
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p, j * 64, i * 100);
            }
            else if (map[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_w, j * 64, i * 64);
            else
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_f, j * 64, i * 64);     
            j++;
        }
        i++;
    }
}
