/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:21:27 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 13:21:35 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../headers/so_long.h"

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

t_list	*ft_new_elem(char *str)
{
	t_list	*elem;
	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem || !str)
		return (NULL);	
	elem->lign = ft_strdup(str);
	if (!elem->lign)
		return (NULL);
	elem->lign_len = ft_strlen(elem->lign);
	elem->nb_exit = item_in_lign('E', elem->lign);
	elem->nb_pos = item_in_lign('P', elem->lign);
	elem->nb_item = item_in_lign('C', elem->lign);
	elem->next = NULL;
	return (elem);
}

int	ft_list_push_back(t_list **begin, char *lign)
{
	t_list *list;

	list = *begin;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_elem(lign);
		if(!list->next)
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

void	display_list(t_list *begin)
{
	t_list *list;

	list = begin;
	if (list)
	{
		while (list)
		{
			printf("lign : %s", list->lign);
			printf("len : %d\n", list->lign_len);
			printf("exit : %d\n", list->nb_exit);
			printf("pos : %d\n", list->nb_pos);
			printf("item : %d\n\n", list->nb_item);
			list = list->next;
		}
	}
}
