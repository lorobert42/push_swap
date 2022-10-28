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

static int	ft_is_sorted(t_list **a)
{
	t_list	*tmp;
	int		max;

	max = 0;
	tmp = *a;
	while (tmp)
	{
		if (get_c(tmp) < max)
			return (0);
		max = get_c(tmp);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_sort_3(t_list **a)
{
	if (ft_is_sorted(a))
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
}
