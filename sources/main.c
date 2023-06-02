/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:12:25 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/31 10:25:11 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"


int	main(int argc, char **argv)
{
	t_lign	*list;
	t_map	data;

	list = NULL;
	if (!parsing(argc, argv, &list))
	{
		ft_printf("Error Parsing\n");
		return (0);
	}
	ft_printf("Parsing OK\n");
	////// COMPTEUR DE MOUVEMENTS
	free_list(&list);
	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	data.height = 600;
	data.width = 800;
	// data.image_c = NULL;
	if (!loop(&data))
	{
		ft_printf("Error Loop\n");
		return (0);
	}
	return (0);
}
