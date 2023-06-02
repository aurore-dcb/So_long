/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:12:25 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/30 14:14:24 by aducobu          ###   ########.fr       */
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
		ft_printf("Error\nParsing\n");
		return (0);
	}
	ft_printf("Parsing OK\n");
	////// COMPTEUR DE MOUVEMENTS
	free_list(&list);
	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	if (!loop(&data))
	{
		ft_printf("Error\nLoop\n");
		return (0);
	}
	return (0);
}
