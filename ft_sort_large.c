/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:14:51 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:24 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	ft_sort_large(t_stack *a, t_tab *goal)
{
	t_stack	*b;
	t_chunk	*chunks;
	int		down;

	if (ft_is_sorted(a))
		exit(0);
	chunks = ft_chunks(a, goal);
	if (!chunks)
		ft_error(a, goal);
	b = ft_init_stack('b');
	if (!b)
		ft_error(a, goal);
	ft_move_chunks(a, b, goal, chunks);
	down = 0;
	while (b->size || down)
		ft_move_back(a, b, goal, &down);
	free(chunks);
	ft_clear_stack(b);
}

void	ft_move_chunks(t_stack *a, t_stack *b, t_tab *goal, t_chunk *chunk)
{
	while (a->size > 3)
	{
		while (ft_get_c(a->list) > chunk->end || \
			ft_get_c(a->list) < chunk->start)
		{
			if (ft_index_limit(a->list, chunk->start, chunk->end) <= \
				ft_rev_index_limit(a->list, chunk->start, chunk->end))
				ft_rotate(a, 1);
			else
				ft_rrotate(a, 1);
		}
		ft_push(b, a, 1);
		if (ft_get_c(b->list) < chunk->mid)
			ft_rotate(b, 1);
		if (!ft_find_between(a, chunk->start, chunk->end))
			ft_update_chunk(chunk, goal);
	}
	ft_sort_3(a);
}
