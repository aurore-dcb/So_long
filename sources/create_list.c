/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:21:27 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 10:29:05 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../headers/so_long.h"

int item_in_lign(char c, char *str)
{
    int i;
    int nb;
    
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
	elem->lign = malloc(sizeof(ft_strlen(str) + 1));
	if (!elem->lign)
		return (NULL);
	elem->lign = ft_strlcpy(elem->valeur, str, ft_strlen(str) + 1);
	elem->lign_len = ft_strlen(elem->lign);
	elem->nb_exit = item_in_lign("E");
	elem->nb_pos = item_in_lign("P");
	elem->nb_item = item_in_lign("C");
	elem->next = NULL;
    return (elem);
}

int	ft_list_push_back(t_list **begin)
{
	if (*begin)
	{
	}
	else
	{
		*begin = ft_new_elem()
	}
}