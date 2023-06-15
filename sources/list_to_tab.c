/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:26:18 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/15 16:06:40 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"

char	**list_to_tab(t_lign **begin)
{
	int		i;
	int		j;
	char	**map;
	t_lign	*lst;

	lst = *begin;
	if (!lst)
		return (0);
	map = malloc(sizeof(char *) * (ft_lstsize(*begin) + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (lst)
	{
		map[i] = malloc(sizeof(char) * (ft_strlen(lst->lign) + 1));
		if (!map[i])
			return (free_tab(map), NULL);
		j = -1;
		while (++j < lst->lign_len)
			map[i][j] = lst->lign[j];
		map[i++][j] = 0;
		lst = lst->next;
	}
	map[i] = 0;
	return (map);
}
