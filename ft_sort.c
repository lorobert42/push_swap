/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/19 10:17:52 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	ft_is_sorted(t_list *a)
{
	int		max;

	if (!a)
		return (1);
	max = ft_get_c(a);
	while (a)
	{
		if (ft_get_c(a) < max)
			return (0);
		max = ft_get_c(a);
		a = a->next;
	}
	return (1);
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

static void	ft_sort_3(t_stack *a)
{
	if (ft_is_sorted(a->values))
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

static void	ft_sort_large(t_stack *a, t_tab *sorted)
{
	t_stack	*b;
	t_tab	*chunks;
	int		i;

	chunks = ft_sorted_chunks(sorted, a);
	if (!chunks)
		ft_error(a, sorted);
	if (ft_is_sorted(a->values))
		exit(0);
	b = malloc(sizeof(t_stack));
	b->values = NULL;
	b->name = 'b';

	i = 0;
	while (i < chunks->size)
	{
		while (ft_get_c(a->values) > chunks->tab[i])
		{
			if (ft_index_limit(a->values, chunks->tab[i]) <= ft_rev_index_limit(a->values, chunks->tab[i]))
				ft_rotate(a, 1);
			else
				ft_rrotate(a, 1);
		}
		ft_push(b, a);
		if (ft_get_min(a->values) >= chunks->tab[i])
			i++;
	}

	while (ft_lstsize(a->values) > 3)
	{
		// if (ft_index(a->values, ft_get_min(a->values)) == 1)
		// 	ft_swap(a, 1);
		if (ft_index(a->values, ft_get_min(a->values)) && ft_index(a->values, ft_get_min(a->values)) <= ft_rev_index(a->values, ft_get_min(a->values)))
			ft_rotate(a, 1);
		else if (ft_index(a->values, ft_get_min(a->values)))
			ft_rrotate(a, 1);
		else
			ft_push(b, a);
	}

	ft_sort_3(a);

	while (b->values)
	{
		if (ft_index(b->values, ft_get_max(b->values)) == 1)
			ft_swap(b, 1);
		if (ft_index(b->values, ft_get_max(b->values)) && ft_index(b->values, ft_get_max(b->values)) <= ft_rev_index(b->values, ft_get_max(b->values)))
			ft_rotate(b, 1);
		else if (ft_index(b->values, ft_get_max(b->values)))
			ft_rrotate(b, 1);
		else
			ft_push(a, b);
	}

	free(chunks->tab);
	free(chunks);
}

static void	ft_sort_10(t_stack *a)
{
	t_stack	*b;

	if (ft_is_sorted(a->values))
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
