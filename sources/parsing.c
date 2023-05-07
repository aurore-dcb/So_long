/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:01 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 10:21:44 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../gnl/get_next_line.h"

int extension(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (i < 5)
		return (0);
	if (!s[i - 1] || s[i - 1] != 'r')
		return (0);
	if (!s[i - 2] || s[i - 2] != 'e')
		return (0);
	if (!s[i - 3] || s[i - 3] != 'b')
		return (0);
	if (!s[i - 4] || s[i - 4] != '.')
		return (0);
	return (1);
}


// rectangle, 1 sortie, 1 depart, >= 1 item, murs autour
// chemin valide
int map_format(char *file)
{
	t_list	*list;
	// mettre dans une liste chainee

	
	
}

int	parsing(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!extension(argv[1]))
		return (0);
	return (1);
}