/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:01 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/29 16:34:44 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"

int	verifs(char *file, t_lign **list)
{
	char	**map;

	create_list(list, file);
	if (!is_rectangle(list))
		return (0);
	if (!composition(list))
		return (0);
	if (!five_char(list))
		return (0);
	if (!walls(list))
		return (0);
	map = list_to_tab(list);
	if (!map)
		return (0);
	cross_map(map);
	if (!valid_path(map))
		return (free_tab(map), 0);
	free_tab(map);
	return (1);
}

// chemin valide
int	parsing(int argc, char **argv, t_lign **list)
{
	if (argc != 2)
		return (0);
	if (!extension(argv[1]))
		return (0);
	if (!verifs(argv[1], list))
		return (0);
	return (1);
}
