/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:49:44 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 11:03:18 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"

int	to_cross(char c)
{
	return (c != '1' && c != 'X' && c != 'P');
}

int	add_cross(char **map, int i, int j)
{
	int	res;

	res = 0;
	if (to_cross(map[i - 1][j]))
	{
		res = 1;
		map[i - 1][j] = 'X';
	}
	if (to_cross(map[i][j + 1]))
	{
		res = 1;
		map[i][j + 1] = 'X';
	}
	if (to_cross(map[i + 1][j]))
	{
		res = 1;
		map[i + 1][j] = 'X';
	}
	if (to_cross(map[i][j - 1]))
	{
		res = 1;
		map[i][j - 1] = 'X';
	}
	return (res);
}

void	cross_map(char **map)
{
	int	i;
	int	j;
	int	modif;

	i = 0;
	j = 0;
	modif = 1;
	while (modif == 1)
	{
		modif = 0;
		while (map[i + 1])
		{
			j = 0;
			while (map[i][j + 1])
			{
				if (map[i][j] == 'X' || map[i][j] == 'P')
					if (add_cross(map, i, j))
						modif = 1;
				j++;
			}
			i++;
		}
		i = 0;
	}
}

int	valid_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
