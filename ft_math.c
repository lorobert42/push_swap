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

int	ft_stack_mean(t_list **a)
{
	t_list	*tmp;
	int 	mean;

	mean = 0;
	tmp = *a;
	while (tmp)
	{
		mean += ft_get_c(tmp);
		tmp = tmp->next;
	}
	return (mean / ft_lstsize(*a));
}

int	ft_half_sorted(t_list **a, int mean)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (ft_get_c(tmp) < mean)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_below(t_list **a, int threshold)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (ft_get_c(tmp) < threshold)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_is_above(t_list **a, int threshold)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (ft_get_c(tmp) >= threshold)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_get_front_index(t_list **a, int value)
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

int	ft_get_back_index(t_list **a, int value)
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

int	ft_stack_median(t_tab *tab)
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