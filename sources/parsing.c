/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:01 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 15:44:29 by aducobu          ###   ########.fr       */
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

int	is_rectangle(t_list **begin)
{
	t_list	*list;

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

int	composition(t_list **begin)
{
	int		e;
	int		p;
	int		i;
	t_list	*list;

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

int	five_char(t_list **begin)
{
	int		i;
	t_list	*list;

	list = *begin;
	while (list)
	{
		i = 0;
		while (list->lign[i])
		{
			if (list->lign[i] != '0' && list->lign[i] != '1'
				&& list->lign[i] != 'C' && list->lign[i] != 'E'
				&& list->lign[i] != 'P')
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

int	walls(t_list **begin)
{
	int		i;
	t_list	*list;

	i = 0;
	list = *begin;
	while (list->lign[i])
		if (list->lign[i++] != '1')
			return (0);
	while (list->next)
	{
		if (list->lign[0] != '1'
			|| list->lign[ft_strlen(list->lign)
				- 1] != '1')
			return (0);
		list = list->next;
	}
	i = 0;
	while (list->lign[i])
		if (list->lign[i++] != '1')
			return (0);
	return (1);
}

int	verifs(char *file)
{
	t_list	*list;

	list = NULL;
	create_list(&list, file);
	display_list(list);
	if (!is_rectangle(&list))
		return (0);
	if (!composition(&list))
		return (0);
	if (!five_char(&list))
		return (0);
	if (!walls(&list))
	{
		free_list(&list);
		return (0);
	}
	free_list(&list);
	return (1);
}

// chemin valide
int	parsing(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!extension(argv[1]))
		return (0);
	printf("extension ok\n");
	if (!verifs(argv[1]))
		return (0);
	return (1);
}
