/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 09:41:16 by lorobert         ###   ########.fr       */
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

static void	ft_sort_3(t_stack *a)
{
	if (ft_is_sorted(a->values))
		return ;
	if (ft_get_c(a->values) == ft_get_min(a->values))
	{
		ft_swap(a, 1);
		ft_rotate(a, 1);
	}
	else if (ft_get_c(a->values) == ft_get_max(a->values) && \
			ft_get_c(a->values->next) == ft_get_min(a->values))
		ft_rotate(a, 1);
	else if (ft_get_c(a->values) == ft_get_max(a->values))
	{
		ft_swap(a, 1);
		ft_rrotate(a, 1);
	}
	else if (ft_get_c(a->values->next) == ft_get_min(a->values))
		ft_swap(a, 1);
	else
		ft_rrotate(a, 1);
}

static void	ft_sort_large(t_stack *a, t_tab *sorted)
{
	t_stack	*b;
	t_tab	*chunks;
	int		i;
	int		n_down;

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
		if (ft_index(a->values, ft_get_min(a->values)) && ft_index(a->values, ft_get_min(a->values)) <= ft_rev_index(a->values, ft_get_min(a->values)))
			ft_rotate(a, 1);
		else if (ft_index(a->values, ft_get_min(a->values)))
			ft_rrotate(a, 1);
		else
			ft_push(b, a);
	}

	ft_sort_3(a);

	n_down = 0;
	while (b->values || n_down)
	{
		if (b->values && ft_index(b->values, ft_get_max(b->values)) == 0 && (ft_sorted_index(sorted, ft_get_c(b->values)) == ft_sorted_index(sorted, ft_get_c(a->values)) - 1 || (ft_sorted_index(sorted, ft_get_c(b->values)) == 0 && !n_down)))
			ft_push(a, b);
		else if (!b->values && n_down)
		{
			ft_rrotate(a, 1);
			n_down--;
		}
		else if (ft_get_max(b->values) < ft_get_c(ft_lstlast(a->values)) && n_down)
		{
			ft_rrotate(a, 1);
			n_down--;
		}
		else if (n_down == 0 || ft_get_c(b->values) > ft_get_c(ft_lstlast(a->values)))
		{
			ft_push(a, b);
			ft_rotate(a, 1);
			n_down++;
		}
		else
		{
			if (ft_index(b->values, ft_get_max(b->values)) <= ft_rev_index(b->values, ft_get_max(b->values)))
				ft_rotate(b, 1);
			else
				ft_rrotate(b, 1);
		}
	}

	//ft_printf("%d\n", n_down);

	free(chunks->tab);
	free(chunks);
}

static void	ft_sort_small(t_stack *a, t_tab *sorted)
{
	t_stack	*b;

	if (ft_is_sorted(a->values))
		return ;
	b = ft_init_stack('b');
	if (!b)
		ft_error(a, sorted);
	while (a->size > 3)
		ft_push(b, a);
	ft_sort_3(a);
	while (b->size)
	{
		while (ft_find_position(ft_get_c(b->values), a->values) <= a->size / 2)
			ft_rotate(a, 1);
		while (ft_find_position(ft_get_c(b->values), a->values) > a->size / 2)
			ft_rrotate(a, 1);
		ft_push(a, b);
	}
	while (ft_index(a->values, ft_get_min(a->values)) <= a->size / 2)
		ft_rotate(a, 1);
	while (ft_index(a->values, ft_get_min(a->values)) > a->size / 2)
		ft_rrotate(a, 1);
}

void	ft_sort(t_stack *a, t_tab *sorted)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
	{
		if (ft_get_c(a->values) > ft_get_c(a->values->next))
			ft_swap(a, 1);
		return ;
	}
	else if (a->size == 3)
		return (ft_sort_3(a));
	else if (a->size > 3 && a->size <= 10)
		return (ft_sort_small(a, sorted));
	else
		return (ft_sort_large(a, sorted));
}
