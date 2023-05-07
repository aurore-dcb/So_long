/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:12:25 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 11:17:23 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../gnl/get_next_line.h"

int	main(int argc, char **argv)
{
	if (parsing(argc, argv))
	{
		printf("Parsing OK\n");
	}
	else
	{
		printf("Error\nParsing\n");
	}
	return (0);
}
