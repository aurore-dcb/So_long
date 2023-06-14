/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:21:27 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/14 09:45:56 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"

int	item_in_lign(char c, char *str)
{
	int	i;
	int	nb;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

t_lign	*ft_new_elem(char *str)
{
	t_lign	*elem;

	elem = (t_lign *)malloc(sizeof(t_lign));
	if (!elem || !str)
		return (NULL);
	elem->lign = ft_strdup_trim(str);
	if (!elem->lign)
		return (NULL);
	elem->lign_len = ft_strlen(elem->lign);
	elem->nb_exit = item_in_lign('E', elem->lign);
	elem->nb_pos = item_in_lign('P', elem->lign);
	elem->nb_item = item_in_lign('C', elem->lign);
	elem->next = NULL;
	return (elem);
}

int	ft_list_push_back(t_lign **begin, char *lign)
{
	t_lign	*list;

	list = *begin;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_elem(lign);
		if (!list->next)
			return (0);
	}
	else
	{
		*begin = ft_new_elem(lign);
		if (!(*begin))
			return (0);
	}
	return (1);
}

int	create_list(t_lign **list, char *file)
{
	int		fd;
	char	*lign;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	lign = get_next_line(fd);
	if (!lign)
		return (0);
	while (lign)
	{
		if (!ft_list_push_back(list, lign))
		{
			free_list(list);
			return (0);
		}
		free(lign);
		lign = get_next_line(fd);
	}
	close(fd);
	free(lign);
	return (1);
}

// a supprimer a la fin
// void	display_list(t_lign *begin)
// {
// 	t_lign	*list;

// 	list = begin;
// 	if (list)
// 	{
// 		while (list)
// 		{
// 			ft_printf("lign : %s.\n", list->lign);
// 			ft_printf("len : %d\n", list->lign_len);
// 			ft_printf("exit : %d\n", list->nb_exit);
// 			ft_printf("pos : %d\n", list->nb_pos);
// 			ft_printf("item : %d\n\n", list->nb_item);
// 			list = list->next;
// 		}
// 	}
// }
