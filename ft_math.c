/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:28 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:32 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_index_limit(t_list *a, int min, int max)
{
	int	index;

	index = 0;
	while (a)
	{
		if (ft_get_c(a) >= min && ft_get_c(a) <= max)
			return (index);
		a = a->next;
		index++;
	}
	return (-1);
}

int	ft_rev_index_limit(t_list *a, int min, int max)
{
	t_list	*tmp;
	int		index;
	int		i;

	tmp = a;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) >= min && ft_get_c(tmp) <= max)
			index = i;
		tmp = tmp->next;
		i++;
	}
	return (ft_lstsize(a) - index);
}

int	ft_index(t_stack *a, int value)
{
	t_list	*tmp;
	int		index;

	tmp = a->list;
	index = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

int	ft_rev_index(t_list *a, int value)
{
	t_list	*tmp;
	int		index;
	int		i;

	tmp = a;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) == value)
			index = i;
		tmp = tmp->next;
		i++;
	}
	return (ft_lstsize(a) - index);
}
