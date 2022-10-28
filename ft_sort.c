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
	max = get_c(*a);
	tmp = *a;
	while (tmp)
	{
		if ((direction == '<' && get_c(tmp) < max) ||
		(direction == '>' && get_c(tmp) > max))
			return (0);
		max = get_c(tmp);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_sort_large(t_list **a)
{
	t_list	*b;

	if (ft_is_sorted(a, '<'))
		exit(0);
	b = NULL;
	while (!ft_is_sorted(&b, '>') || (*a && ft_is_sorted(&b, '>')))
	{
		if (!b)
			ft_push(&b, a, "pb\n");
		else
		{
			if (get_c(b) > get_c(*a))
			{
				ft_push(a, &b, "pa\n");
				ft_swap(a, "sa\n");
			}
			else
			{
				ft_push(&b, a, "pb\n");
			}
		}
	}
	while (b)
	{
		ft_push(a, &b, "pa\n");
	}
}

static void	ft_sort_3(t_list **a)
{
	if (ft_is_sorted(a, '<'))
		return ;
	if (get_c(*a) < get_c((*a)->next))
	{
		if (get_c(*a) < get_c(ft_lstlast(*a)))
			ft_printf("sa\nra\n");
		else
			ft_printf("rra\n");
	}
	else
	{
		if (get_c(*a) < get_c(ft_lstlast(*a)))
			ft_printf("sa\n");
		else
		{
			if (get_c((*a)->next) < get_c(ft_lstlast(*a)))
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
		if (get_c(*a) > get_c((*a)->next))
			ft_printf("sa\n");
		return ;
	}
	else if (len == 3)
		return (ft_sort_3(a));
	else
		return (ft_sort_large(a));
}
