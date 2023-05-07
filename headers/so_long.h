/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:14:37 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/07 13:23:05 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_list
{
	char			*lign;
	int				lign_len;
	int				nb_exit;
	int				nb_pos;
	int				nb_item;
	struct s_list	*next;
}					t_list;

// utils.c
int					ft_strlen(char *s);
char				*ft_strdup(char *src);
// char				*ft_strcpy(char *dest, char *src);
void				free_list(t_list **begin);
// parsing.c
int					extension(char *s);
int					parsing(int argc, char **argv);
// create_list.c
t_list				*ft_new_elem(char *str);
int					ft_list_push_back(t_list **begin, char *lign);
void				display_list(t_list *begin);

#endif
