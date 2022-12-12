/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:52:35 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:31 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_tab	*ft_init_tab(void)
{
	t_tab	*t;

	t = malloc(sizeof(t_tab));
	if (!t)
		return (NULL);
	t->size = 0;
	t->tab = NULL;
	return (t);
}

void	ft_clear_tab(t_tab *t)
{
	if (!t)
		return ;
	free(t->tab);
	t->tab = NULL;
	free(t);
}

int	ft_sorted_index(t_tab *tab, int n)
{
	int	i;

	i = 0;
	while (i < tab->size)
	{
		if (tab->tab[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_sort_tab(t_tab *tab)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < tab->size)
	{
		j = i;
		while (j > 0 && tab->tab[j - 1] > tab->tab[j])
		{
			temp = tab->tab[j];
			tab->tab[j] = tab->tab[j - 1];
			tab->tab[j - 1] = temp;
			j--;
		}
		i++;
	}
}

void	ft_print_tab(t_tab *t)
{
	int	i;

	i = 0;
	while (i < t->size)
	{
		ft_printf("%d", t->tab[i]);
		if (i < t->size - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("\n");
}
