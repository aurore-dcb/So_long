/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:17:48 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/02 16:50:48 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

// fonction determiner si un collectible a ete ramasse ou pas
void    display_collectible(t_map *data, t_item **lst_item, int i, int j)
{
    t_item *begin;

    begin = *lst_item;
    if (begin)
    {
        printf("x = %d\ny = %d\n", begin->x, begin->y);
        if (begin->x == j && begin->y == i)
        {
            if (begin->active)
            {
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_c, j * 64, i * 64);
                begin->active = 0;
            }
            else
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_f, j * 64, i * 64);
        }
        begin = begin->next;
    }
}

void display_map(t_map *data, char **map, t_item **lst_item)
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
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p, j * 64, i * 64);
            else if (map[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_w, j * 64, i * 64);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_e, j * 64, i * 64);
            else if (map[i][j] == 'C')
                display_collectible(data, lst_item, i, j);
            else
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_f, j * 64, i * 64);     
            j++;
        }
        i++;
    }
}
