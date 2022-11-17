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

static int	ft_is_sorted(t_list *a, char direction)
{
	t_list	*tmp;
	int		max;

	if (!a)
		return (1);
	max = ft_get_c(a);
	tmp = a;
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

static void	ft_sort_large(t_stack *a, t_tab *sorted)
{
	t_stack	*b;
	int 	median;

	median = ft_sorted_median(sorted);
	if (ft_is_sorted(a->values, '<'))
		exit(0);
	b = malloc(sizeof(t_stack));
	b->values = NULL;
	b->name = 'b';
	//ft_printf("%d\n", median);
	//ft_print_stack(a->values, b->values);
//	while (ft_get_min(a->values) > median)
//	{
//		if (ft_get_c(ft_lstlast(a->values)) < ft_get_c(a->values->next) && ft_get_c(ft_lstlast(a->values)) < ft_get_c(a->values) &&
//				ft_get_c(a->values) <= median)
//		{
//			ft_rrotate(a, 1);
//		}
//		else if (ft_get_c(a->values->next) < ft_get_c(a->values) && ft_get_c(a->values->next) < ft_get_c(ft_lstlast(a->values)) && ft_get_c(a->values) <= median)
//		{
//			ft_swap(a, 1);
//		}
//		else
//			ft_rotate(a, 1);
//		while (ft_find_rev_position(ft_get_c(a->values), b->values) != 0)
//		{
//			if (ft_find_rev_position(ft_get_c(a->values), b->values) > ft_lstsize(b->values) / 2)
//				ft_rrotate(b, 1);
//			else
//				ft_rotate(b, 1);
//		}
//		ft_push(b, a);
//		//ft_print_stack(a->values, b->values);
//	}
	//ft_print_stack(a->values, b->values);
	while (!ft_is_pseudosorted(a->values))
	{
		if (ft_get_c(ft_lstlast(a->values)) < ft_get_c(a->values->next) && ft_get_c(ft_lstlast(a->values)) < ft_get_c(a->values))
		{
			ft_rrotate(a, 1);
		}
		else if (ft_get_c(a->values->next) < ft_get_c(a->values) && ft_get_c(a->values->next) < ft_get_c(ft_lstlast(a->values)))
		{
			ft_swap(a, 1);
		}
		while (ft_find_rev_position(ft_get_c(a->values), b->values) != 0)
		{
			if (ft_find_rev_position(ft_get_c(a->values), b->values) > ft_lstsize(b->values) / 2)
				ft_rrotate(b, 1);
			else
				ft_rotate(b, 1);
		}
		ft_push(b, a);
		//ft_print_stack(a->values, b->values);
	}
	while (b->values && (ft_get_c(a->values) != ft_get_min(a->values) || ft_get_c(b->values) != ft_get_max(b->values)))
	{
		if (ft_index(a->values, ft_get_min(a->values)) && ft_index(a->values, ft_get_min(a->values)) <= ft_rev_index(a->values, ft_get_min(a->values)))
		{
			if (ft_index(b->values, ft_get_max(b->values)) && ft_index(b->values, ft_get_max(b->values)) <= ft_rev_index(b->values, ft_get_max(b->values)))
				ft_rotate_both(a, b);
			else
				ft_rotate(a, 1);
		}
		else if (ft_index(a->values, ft_get_min(a->values)))
		{
			if (ft_index(b->values, ft_get_max(b->values)) && ft_index(b->values, ft_get_max(b->values)) > ft_index(b->values, ft_get_max(b->values)))
				ft_rrotate_both(a, b);
			else
				ft_rrotate(a, 1);
		}
		if (ft_index(b->values, ft_get_max(b->values)) && ft_index(b->values, ft_get_max(b->values)) <= ft_rev_index(b->values, ft_get_max(b->values)))
			ft_rotate(b, 1);
		else if (ft_index(b->values, ft_get_max(b->values)))
			ft_rrotate(b, 1);
		//ft_print_stack(a->values, b->values);
	}
	while (b->values)
	{
		if (ft_find_position(ft_get_c(b->values), a->values) < ft_lstsize(a->values) / 2)
		{
			while (ft_find_position(ft_get_c(b->values), a->values))
				ft_rotate(a, 1);
		}
		else
		{
			while (ft_find_position(ft_get_c(b->values), a->values))
				ft_rrotate(a, 1);
		}
		ft_push(a, b);
		//ft_print_stack(a->values, b->values);
	}
	if (ft_index(a->values, ft_get_min(a->values)) < ft_lstsize(a->values) / 2)
	{
		while (ft_get_c(a->values) != ft_get_min(a->values))
			ft_rotate(a, 1);
	}
	else
	{
		while (ft_get_c(a->values) != ft_get_min(a->values))
			ft_rrotate(a, 1);
	}
	//ft_print_stack(a->values, b->values);
}

static void	ft_sort_3(t_stack *a)
{
	if (ft_is_sorted(a->values, '<'))
		return ;
	if (ft_get_c(a->values) < ft_get_c(a->values->next))
	{
		if (ft_get_c(a->values) < ft_get_c(ft_lstlast(a->values)))
		{
			ft_swap(a, 1);
			ft_rotate(a, 1);
		}
		else
			ft_rrotate(a, 1);
	}
	else
	{
		if (ft_get_c(a->values) < ft_get_c(ft_lstlast(a->values)))
			ft_swap(a, 1);
		else
		{
			if (ft_get_c(a->values->next) < ft_get_c(ft_lstlast(a->values)))
				ft_rotate(a, 1);
			else
			{
				ft_swap(a, 1);
				ft_rrotate(a, 1);
			}
		}
	}
}

static void	ft_sort_10(t_stack *a)
{
	t_stack	*b;

	if (ft_is_sorted(a->values, '<'))
		return ;
	b = malloc(sizeof(t_stack));
	b->values = NULL;
	b->name = 'b';
	while (ft_lstsize(a->values) > 3)
		ft_push(b, a);
	ft_sort_3(a);
	while (b->values)
	{
		if (ft_find_position(ft_get_c(b->values), a->values) < ft_lstsize(a->values) / 2)
		{
			while (ft_find_position(ft_get_c(b->values), a->values))
				ft_rotate(a, 1);
		}
		else
		{
			while (ft_find_position(ft_get_c(b->values), a->values))
				ft_rrotate(a, 1);
		}
		ft_push(a, b);
		//ft_print_stack(a->values, b->values);
	}
	if (ft_index(a->values, ft_get_min(a->values)) < ft_lstsize(a->values) / 2)
	{
		while (ft_get_c(a->values) != ft_get_min(a->values))
			ft_rotate(a, 1);
	}
	else
	{
		while (ft_get_c(a->values) != ft_get_min(a->values))
			ft_rrotate(a, 1);
	}
	//ft_print_stack(a->values, b->values);
}

void	ft_sort(t_stack *a, int len, t_tab *sorted)
{
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if (ft_get_c(a->values) > ft_get_c(a->values->next))
			ft_printf("sa\n");
		return ;
	}
	else if (len == 3)
		return (ft_sort_3(a));
	else if (len > 3 && len < 10)
		return (ft_sort_10(a));
	else
		return (ft_sort_large(a, sorted));
}
