/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:13:44 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/30 14:17:09 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int key_hook(int keycode, void *param)
{
	if (keycode == 65307)
	{
		void *win_ptr = param;
    	void *mlx_ptr = mlx_get_data_addr(win_ptr, NULL, NULL, NULL);
		mlx_destroy_window(mlx_ptr, win_ptr);
	}
    return 0;
}

int close_window(void *param)
{
	void *win_ptr = param;
    void *mlx_ptr = mlx_get_data_addr(win_ptr, NULL, NULL, NULL);
	mlx_destroy_window(mlx_ptr, win_ptr);
	return 0;
}

int loop(t_map *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "So_long");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr), 0);
    

        
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data->win_ptr);  // "ESC" pour fermer 
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data->win_ptr); // Croix pour fermer
    mlx_loop(data->mlx_ptr); // boucle affichage fenetre
	return (1);
}
