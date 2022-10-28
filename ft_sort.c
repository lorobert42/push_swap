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

static void	ft_sort_large(t_list **a)
{
	t_list	*b;
	int 	mean;
	int 	half_sorted;

	if (ft_is_sorted(a, '<'))
		exit(0);
	b = NULL;
	mean = ft_stack_mean(a);
	half_sorted = 0;
	while (!ft_is_sorted(&b, '>') || (*a && ft_is_sorted(&b, '>')))
	{
		if (!half_sorted && *a && (*a)->next && ft_get_c(*a) > mean)
		{
			ft_rotate(a, ' ', "ra\n");
			half_sorted = ft_half_sorted(a, mean);
			continue ;
		}
		if (*a && (*a)->next && ft_get_c(*a) > ft_get_c((*a)->next))
			ft_swap(a, "sa\n");
		if (!b)
			ft_push(&b, a, "pb\n");
		else
		{
			if (ft_get_c(b) > ft_get_c(*a))
			{
				ft_push(a, &b, "pa\n");
				ft_swap(a, "sa\n");
			}
			else
				ft_push(&b, a, "pb\n");
		}
	}
	while (b)
	{
		ft_push(a, &b, "pa\n");
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

void	ft_sort(t_list **a, int len)
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
		return (ft_sort_large(a));
}
