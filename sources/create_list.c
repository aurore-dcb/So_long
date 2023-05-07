/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:21:27 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 11:58:07 by aducobu          ###   ########.fr       */
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
	while (str[i])
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

	elem = malloc(sizeof(t_list));
	if (!elem || !str)
		return (NULL);
	printf("new_elem\n");
	elem->lign = malloc(sizeof(ft_strlen(str) + 1));
	if (!elem->lign)
		return (NULL);
	printf("ft_strlen(str) = %d\n", ft_strlen(str));
	elem->lign = ft_strcpy(elem->lign, str);
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
		printf("if\n");
		while (list->next)
			list = list->next;
		list->next = ft_new_elem(lign);
		printf("test\n");
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
