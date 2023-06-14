/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:12:25 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 11:43:39 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	find_x(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_y(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_lign	*list;
	t_map	data;

	list = NULL;
	if (!parsing(argc, argv, &list))
	{
		ft_printf("Error\nParsing\n");
		return (free_list(&list), 0);
	}
	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	data.height = ft_lstsize(list) * 64;
	data.width = list->lign_len * 64;
	data.map = list_to_tab(&list);
	data.right = 1;
	if (!data.map)
		return (0);
	loop(&data);
	free_all(&data, &list);
	return (0);
}
