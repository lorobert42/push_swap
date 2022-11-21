/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:14:51 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 11:29:44 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	ft_sort_large(t_stack *a, t_tab *sorted)
{
	t_stack	*b;
	t_tab	*chunks;
	int		n_down;

	if (ft_is_sorted(a->values))
		exit(0);
	chunks = ft_sorted_chunks(sorted, a);
	if (!chunks)
		ft_error(a, sorted);
	b = ft_init_stack('b');
	if (!b)
		ft_error(a, sorted);
	ft_move_chunks(a, b, chunks);
	n_down = 0;
	while (b->size || n_down)
	{
		ft_move_back(a, b, sorted, &n_down);
	}
	free(chunks->tab);
	free(chunks);
	ft_clear_stack(b);
}

void	ft_move_chunks(t_stack *a, t_stack *b, t_tab *chunks)
{
	int	i;

	i = 0;
	while (i < chunks->size)
	{
		while (ft_get_c(a->values) > chunks->tab[i])
		{
			if (ft_index_limit(a->values, chunks->tab[i]) <= \
					ft_rev_index_limit(a->values, chunks->tab[i]))
				ft_rotate(a, 1);
			else
				ft_rrotate(a, 1);
		}
		ft_push(b, a);
		if (ft_get_min(a->values) >= chunks->tab[i])
			i++;
	}
	ft_move_last_chunk(a, b);
}

void	ft_move_last_chunk(t_stack *a, t_stack *b)
{
	while (ft_lstsize(a->values) > 3)
	{
		if (ft_index(a->values, ft_get_min(a->values)) && \
				ft_index(a->values, ft_get_min(a->values)) <= \
				ft_rev_index(a->values, ft_get_min(a->values)))
			ft_rotate(a, 1);
		else if (ft_index(a->values, ft_get_min(a->values)))
			ft_rrotate(a, 1);
		else
			ft_push(b, a);
	}
	ft_sort_3(a);
}

void	ft_move_back(t_stack *a, t_stack *b, t_tab *sorted, int *n_down)
{
	if ((b->size && \
			ft_sorted_index(sorted, ft_get_c(ft_lstlast(a->values))) == \
			ft_sorted_index(sorted, ft_get_c(a->values)) - 1) || \
			(!b->size && *n_down))
	{
		ft_rrotate(a, 1);
		(*n_down)--;
	}
	else if (b->size && ft_index(b->values, ft_get_max(b->values)) == 0)
		ft_push(a, b);
	else if (*n_down == 0 || ft_get_c(b->values) > \
			ft_get_c(ft_lstlast(a->values)))
	{
		ft_push(a, b);
		ft_rotate(a, 1);
		(*n_down)++;
	}
	else if (ft_index(b->values, ft_get_max(b->values)) <= \
			ft_rev_index(b->values, ft_get_max(b->values)))
		ft_rotate(b, 1);
	else
		ft_rrotate(b, 1);
}
