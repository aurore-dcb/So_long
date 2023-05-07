/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:13:48 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 11:40:19 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../headers/so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_list1(t_list **begin)
{
	t_list	*current;
	t_list	*temp;

	current = *begin;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}