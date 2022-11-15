/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/27 15:19:51 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_index(t_list **a, int value)
{
	t_list	*tmp;
	int 	index;

	tmp = *a;
	index = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

int	ft_rev_index(t_list **a, int value)
{
	t_list	*tmp;
	int 	index;
	int 	i;

	tmp = *a;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) == value)
			index = i;
		tmp = tmp->next;
		i++;
	}
	return (ft_lstsize(*a) - index);
}

int	ft_sorted_index(int n, t_tab *tab)
{
	int i;

	i = 0;
	while ( i < tab->size)
	{
		if (tab->tab[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_sorted_median(t_tab *tab)
{
	return (tab->tab[tab->size / 2]);
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