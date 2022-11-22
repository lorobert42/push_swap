/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:28 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_between(t_stack *s, int min, int max)
{
	t_list	*tmp;

	tmp = s->list;
	while (tmp)
	{
		if (ft_get_c(tmp) >= min && ft_get_c(tmp) <= max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_get_min(t_stack *a)
{
	t_list	*tmp;
	int		min;

	tmp = a->list;
	min = ft_get_c(tmp);
	while (tmp && tmp->next)
	{
		if (ft_get_c(tmp->next) < min)
			min = ft_get_c(tmp->next);
		tmp = tmp->next;
	}
	return (min);
}

int	ft_get_max(t_stack *a)
{
	t_list	*tmp;
	int		max;

	tmp = a->list;
	max = ft_get_c(tmp);
	while (tmp && tmp->next)
	{
		if (ft_get_c(tmp->next) > max)
			max = ft_get_c(tmp->next);
		tmp = tmp->next;
	}
	return (max);
}

int	ft_get_c(t_list *a)
{
	return (*(int *)a->content);
}
