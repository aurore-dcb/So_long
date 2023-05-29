/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:26:18 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/29 16:37:13 by aducobu          ###   ########.fr       */
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
	map = malloc(sizeof(char *) * (ft_lstsize(*begin) + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (lst)
	{
		map[i] = malloc(sizeof(char) * (ft_strlen(lst->lign) + 1));
		if (!map[i])
			return (free_list(begin), free_tab(map), NULL);
		j = -1;
		while (++j < lst->lign_len)
			map[i][j] = lst->lign[j];
		map[i++][j] = 0;
		lst = lst->next;
	}
	map[i] = 0;
	return (map);
}

void	display_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("---- map ----\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("---- fin map ----\n");
}
