/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:17:48 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 09:52:51 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"



// fonction determiner si un collectible a ete ramasse ou pas
// void    display_collectible(t_map *data, int i, int j)
// {
//     t_item *begin;

//     begin = data->item;
//     while (begin)
//     {
//         if (begin->x == j && begin->y == i)
//         {
//             if (begin->active)
//             {
//                 mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_c, j * 64, i * 64);
//             }
//             else
//             {
//                 mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_f, j * 64, i * 64);
//             }
//         }
//         begin = begin->next;
//     }
// }

int display_map(t_map *data)
{
    int i;
    int j;

    i = 0;
    // ft_printf("still = %d\n", still_collectible(data));
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_w, j * 64, i * 64);
            else if (i == data->pos_x && j == data->pos_y)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p, j * 64, i * 64);
            else if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_e, j * 64, i * 64);
            else if (data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_c, j * 64, i * 64);
            else
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_f, j * 64, i * 64);     
            j++;
        }
        i++;
    }
    return (1);
}
