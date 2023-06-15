/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:01 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/15 15:38:14 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"

int	verifs(char *file, t_lign **list)
{
	char	**map;

	if (!create_list(list, file))
		return (0);
	if (!is_rectangle(list))
		return (ft_printf("Error\nThe map is not a rectangle\n"), 0);
	if (!composition(list))
		return (ft_printf("Error\nMap composition\n"), 0);
	if (!six_char(list))
		return (ft_printf("Error\nWrong character\n"), 0);
	if (!walls(list))
		return (ft_printf("Error\nThe map is not surrounded by walls\n"), 0);
	map = list_to_tab(list);
	if (!map)
		return (ft_printf("Error\n"), 0);
	cross_map(map);
	if (!valid_path(map))
		return (ft_printf("Error\nInvalid path\n"), free_tab(map), 0);
	free_tab(map);
	return (1);
}

int	parsing(int argc, char **argv, t_lign **list)
{
	if (argc != 2)
		return (0);
	if (!extension(argv[1]))
		return (ft_printf("Error\nWrong extension\n"), 0);
	if (!verifs(argv[1], list))
		return (0);
	return (1);
}
