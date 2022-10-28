/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/27 15:19:51 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	ft_is_sorted(t_list **a, char direction)
{
	t_list	*tmp;
	int		max;

	if (!*a)
		return (0);
	max = ft_get_c(*a);
	tmp = *a;
	while (tmp)
	{
		if ((direction == '<' && ft_get_c(tmp) < max) || \
		(direction == '>' && ft_get_c(tmp) > max))
			return (0);
		max = ft_get_c(tmp);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_sort_large(t_list **a, t_tab *sorted)
{
	t_list	*b;
	int 	median;
	int 	i;

	if (ft_is_sorted(a, '<'))
		exit(0);
	b = NULL;
	median = ft_stack_median(sorted);
	while (ft_is_above(a, median))
	{
		if (ft_get_c(*a) >= median)
			ft_push(&b, a, "pb\n");
		else
			ft_rotate(a, ' ', "ra\n");
	}
	i = sorted->size - 1;
	while (b)
	{
		if (ft_get_c(b) == sorted->tab[i])
		{
			ft_push(a, &b, "pa\n");
			i--;
			continue ;
		}
		if (ft_get_front_index(&b, sorted->tab[i]) < ft_get_back_index(&b, sorted->tab[i]))
			ft_rotate(&b, ' ', "rb\n");
		else
			ft_rotate(&b, 'r', "rrb\n");
	}
	while (ft_is_below(a, median))
	{
		if (ft_get_c(*a) < median)
			ft_push(&b, a, "pb\n");
		else
			ft_rotate(a, 'r', "rra\n");
	}
	i = (sorted->size / 2) - 1;
	while (!ft_is_sorted(a, '<'))
		ft_rotate(a, ' ', "ra\n");
	while (b)
	{
		if (ft_get_c(b) == sorted->tab[i])
		{
			ft_push(a, &b, "pa\n");
			i--;
			continue ;
		}
		if (ft_get_front_index(&b, sorted->tab[i]) < ft_get_back_index(&b, sorted->tab[i]))
			ft_rotate(&b, ' ', "rb\n");
		else
			ft_rotate(&b, 'r', "rrb\n");
	}
}

static void	ft_sort_small(t_list **a)
{
	if (ft_is_sorted(a, '<'))
		return ;
	if (ft_get_c(*a) < ft_get_c((*a)->next))
	{
		if (ft_get_c(*a) < ft_get_c(ft_lstlast(*a)))
			ft_printf("sa\nra\n");
		else
			ft_printf("rra\n");
	}
	else
	{
		if (ft_get_c(*a) < ft_get_c(ft_lstlast(*a)))
			ft_printf("sa\n");
		else
		{
			if (ft_get_c((*a)->next) < ft_get_c(ft_lstlast(*a)))
				ft_printf("ra\n");
			else
				ft_printf("sa\nrra\n");
		}
	}
}

void	ft_sort(t_list **a, int len, t_tab *sorted)
{
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if (ft_get_c(*a) > ft_get_c((*a)->next))
			ft_printf("sa\n");
		return ;
	}
	else if (len == 3)
		return (ft_sort_small(a));
	else
		return (ft_sort_large(a, sorted));
}
