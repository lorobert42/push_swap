/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:56:49 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 11:59:02 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_chunk	*ft_chunks(t_stack *s, t_tab *goal)
{
	t_chunk	*chunk;
	int		div;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	if (s->size <= 10)
		div = 5;
	else if (s->size <= 150)
		div = 8;
	else
		div = 18;
	chunk->size = s->size / div;
	chunk->mid_i = goal->size / 2;
	chunk->mid = goal->tab[chunk->mid_i];
	chunk->start_i = chunk->mid_i - chunk->size;
	chunk->start = goal->tab[chunk->start_i];
	chunk->end_i = chunk->mid_i + chunk->size;
	chunk->end = goal->tab[chunk->end_i];
	return (chunk);
}

void	ft_update_chunk(t_chunk *chunk, t_tab *goal)
{
	chunk->start_i -= chunk->size;
	if (chunk->start_i < 0)
		chunk->start_i = 0;
	chunk->start = goal->tab[chunk->start_i];
	chunk->end_i += chunk->size;
	if (chunk->end_i > goal->size - 4)
		chunk->end_i = goal->size - 4;
	chunk->end = goal->tab[chunk->end_i];
}
