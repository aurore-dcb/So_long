/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:01 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 13:26:24 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../headers/so_long.h"

int	extension(char *s)
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

// rectangle, 1 sortie, 1 depart, >= 1 item, murs autour, que certains char
// chemin valide
int	map_format(char *file)
{
	int	fd;

	t_list *list;
	char *lign;

	list = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	lign = get_next_line(fd);
	while (lign)
	{
		if (!ft_list_push_back(&list, lign))
			return (0);
		free(lign);
		lign = get_next_line(fd);
	}
	close(fd);
	display_list(list);
	free(lign);
	free_list(&list);
	return (1);
}

int	parsing(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!extension(argv[1]))
		return (0);
	printf("extension ok\n");
	if (!map_format(argv[1]))
		return (0);
	return (1);
}