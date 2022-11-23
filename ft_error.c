/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:46:05 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/23 10:27:08 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void	ft_clear_all(t_stack *s1, t_stack *s2, t_tab *t)
{
	ft_clear_stack(s1);
	ft_clear_stack(s2);
	ft_clear_tab(t);
}

void	ft_error(t_stack *s1, t_stack *s2, t_tab *t, char *message)
{
	write(2, message, ft_strlen(message));
	ft_clear_all(s1, s2, t);
	exit(0);
}

int	ft_check_duplicates(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size - 1)
	{
		if (tab->tab[i] == tab->tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}
