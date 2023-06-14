/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:28:43 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 15:16:21 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"

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

int	is_rectangle(t_lign **begin)
{
	t_lign	*list;

	list = *begin;
	if (list && list->next)
	{
		while (list->next)
		{
			if (list->lign_len != list->next->lign_len)
			{
				free_list(begin);
				return (0);
			}
			list = list->next;
		}
	}
	return (1);
}

int	composition(t_lign **begin)
{
	int		e;
	int		p;
	int		i;
	t_lign	*list;

	e = 0;
	p = 0;
	i = 0;
	list = *begin;
	while (list)
	{
		e += list->nb_exit;
		p += list->nb_pos;
		i += list->nb_item;
		list = list->next;
	}
	if (e != 1 || p != 1 || i < 1)
	{
		free_list(begin);
		return (0);
	}
	return (1);
}

int	five_char(t_lign **begin)
{
	int		i;
	t_lign	*list;

	list = *begin;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->lign[i])
		{
			if (list->lign[i] != '0' && list->lign[i] != '1'
				&& list->lign[i] != 'C' && list->lign[i] != 'E'
				&& list->lign[i] != 'P' && list->lign[i] != 'Z')
			{
				free_list(begin);
				return (0);
			}
			i++;
		}
		list = list->next;
	}
	return (1);
}

int	walls(t_lign **begin)
{
	int		i;
	t_lign	*list;

	i = 0;
	list = *begin;
	if (!list)
		return (0);
	while (list->lign[i])
		if (list->lign[i++] != '1')
			return (free_list(begin), 0);
	while (list->next)
	{
		if (list->lign[0] != '1' || list->lign[ft_strlen(list->lign)
				- 1] != '1')
			return (free_list(begin), 0);
		list = list->next;
	}
	i = 0;
	while (list->lign[i])
		if (list->lign[i++] != '1')
			return (free_list(begin), 0);
	return (1);
}
