/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:33:09 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/13 12:22:33 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/libft.h"

void	free_list(t_lign **begin)
{
	t_lign	*current;

	while (*begin != NULL)
	{
		current = *begin;
		(*begin) = (*begin)->next;
		free(current->lign);
		free(current);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_mlx(t_map *data)
{
	if (data->img_p)
		mlx_destroy_image(data->mlx_ptr, data->img_p);
	if (data->img_c)
		mlx_destroy_image(data->mlx_ptr, data->img_c);
	if (data->img_e)
		mlx_destroy_image(data->mlx_ptr, data->img_e);
	if (data->img_w)
		mlx_destroy_image(data->mlx_ptr, data->img_w);
	if (data->img_f)
		mlx_destroy_image(data->mlx_ptr, data->img_f);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void free_map(t_map *data)
{
	free_mlx(data);
	free_tab(data->map);
}