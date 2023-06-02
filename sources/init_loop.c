/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:13:44 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/31 10:36:09 by aducobu          ###   ########.fr       */
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

int	img(t_map *data)
{
	int	w;

	data->img_p = NULL;
	data->img_c = NULL;
	data->img_f = NULL;
	data->img_w = NULL;
	data->img_e = NULL;
	
	data->img_p = mlx_xpm_file_to_image(data->mlx_ptr, "../image/p.xpm", &w, &w);
	if (!data->img_p)
		return (ft_printf("p\n"), 0);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, "../image/c.xpm", &w, &w);
	if (!data->img_c)
		return (ft_printf("c\n"), 0);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, "../image/w.xpm", &w, &w);
	if (!data->img_w)
		return (ft_printf("w\n"), 0);
	data->img_f = mlx_xpm_file_to_image(data->mlx_ptr, "../image/f.xpm", &w, &w);
	if (!data->img_f)
		return (ft_printf("f\n"), 0);
	data->img_e = mlx_xpm_file_to_image(data->mlx_ptr, "../image/e.xpm", &w, &w);
	if (!data->img_e)
		return (ft_printf("e\n"), 0);
	return (1);
}

int loop(t_map *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, "So_long");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr), 0);
    
	if (img(data) == 0)
	{
		ft_printf("error image\n");
		return (0);
	}
	// int w;
	// ft_printf("width = %d\nheight = %d\n", data.width, data.height);
	// data->image_c = mlx_xpm_file_to_image(data->mlx_ptr, "../image/c.xpm", &w, &w);
	// if (data->image_c == NULL)
	// {
	// 	ft_printf("Error image\n");
	// 	return (free(data->win_ptr), 0);
	// }
    // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image_c, 100, 100);
	
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data->win_ptr);  // "ESC" pour fermer 
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data->win_ptr); // Croix pour fermer
    mlx_loop(data->mlx_ptr); // boucle affichage fenetre
	return (1);
}
