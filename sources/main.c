/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:12:25 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/29 18:03:08 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
// #include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_lign	*list;

	list = NULL;
	if (!parsing(argc, argv, &list))
	{
		ft_printf("Error\nParsing\n");
		return (0);
	}
	ft_printf("Parsing OK\n");
	////// COMPTEUR DE MOUVEMENTS
	free_list(&list);
	// void *mlx_ptr = mlx_init();
    // void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Ma première fenêtre");

	// mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFF0000);
    // mlx_loop(mlx_ptr);
	return (0);
}
