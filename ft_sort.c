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
		return (1);
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

static int ft_is_pseudosorted(t_list *a)
{
	t_list	*tmp;
	t_tab	sorted;
	int 	i;

	if (!a)
		return (1);
	sorted.size = ft_lstsize(a);
	sorted.tab = malloc(sizeof(int) * sorted.size);
	tmp = a;
	i = 0;
	while (i < sorted.size)
	{
		sorted.tab[i] = ft_get_c(tmp);
		tmp = tmp->next;
		i++;
	}
	ft_sort_tab(&sorted);
	tmp = a;
	while (tmp->next)
	{
		if (ft_sorted_index(ft_get_c(tmp), &sorted) + 1 != ft_sorted_index(ft_get_c(tmp->next), &sorted) && !(ft_sorted_index(ft_get_c(tmp), &sorted) == sorted.size - 1 && ft_sorted_index(ft_get_c(tmp->next), &sorted) == 0))
		{
			free(sorted.tab);
			return (0);
		}
		tmp = tmp->next;
	}
	free(sorted.tab);
	return (1);
}

static void	ft_sort_large(t_list **a, t_tab *sorted)
{
	t_list	*b;
	int 	rot;

	(void) sorted;
	if (ft_is_sorted(a, '<'))
		exit(0);
	b = NULL;
	//ft_print_stack(*a, b);
	while (!ft_is_pseudosorted(*a))
	{
		if (ft_get_c(ft_lstlast(*a)) < ft_get_c((*a)->next) && ft_get_c(ft_lstlast(*a)) < ft_get_c(*a))
		{
			ft_rrotate(a, "rra\n");
		}
		else if (ft_get_c((*a)->next) < ft_get_c(*a) && ft_get_c((*a)->next) < ft_get_c(
				ft_lstlast(*a)))
		{
			ft_swap(a, "sa\n");
		}
		while (ft_find_position(ft_get_c(*a), b) != 0)
		{
			if (ft_find_position(ft_get_c(*a), b) >= ft_lstsize(b) / 2)
				ft_rrotate(&b, "rrb\n");
			else
				ft_rotate(&b, "rb\n");
		}
		ft_push(&b, a, "pb\n");
		//ft_print_stack(*a, b);
	}
	while (ft_get_c(*a) != ft_get_min(*a) || ft_get_c(b) != ft_get_max(b))
	{
		if (ft_index(a, ft_get_min(*a)) && ft_index(a, ft_get_min(*a)) <= ft_rev_index(a, ft_get_min(*a)))
		{
			if (ft_index(&b, ft_get_max(b)) && ft_index(&b, ft_get_max(b)) <= ft_rev_index(&b, ft_get_max(b)))
			{
				ft_rotate(a, "");
				ft_rotate(&b, "rs\n");
			}
			else
				ft_rotate(a, "ra\n");
		}
		else if (ft_index(a, ft_get_min(*a)))
		{
			if (ft_index(&b, ft_get_max(b)) && ft_index(&b, ft_get_max(b)) > ft_index(&b, ft_get_max(b)))
			{
				ft_rrotate(a, "");
				ft_rrotate(&b, "rrs\n");
			}
			else
				ft_rrotate(a, "rra\n");
		}
		if (ft_index(&b, ft_get_max(b)) && ft_index(&b, ft_get_max(b)) <= ft_rev_index(&b, ft_get_max(b)))
			ft_rotate(&b, "rb\n");
		else if (ft_index(&b, ft_get_max(b)))
			ft_rrotate(&b, "rrb\n");
		//ft_print_stack(*a, b);
	}
	while (b)
	{
		rot = 0;
		while (ft_get_c(*a) < ft_get_c(b))
		{
			ft_rotate(a, "ra\n");
			rot++;
		}
		ft_push(a, &b, "pa\n");
		while (rot > 0)
		{
			ft_rrotate(a, "rra\n");
			rot--;
		}
		//ft_print_stack(*a, b);
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
