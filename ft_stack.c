/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 09:41:32 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_get_min(t_list *a)
{
	t_list	*tmp;
	int		min;

	tmp = a;
	min = ft_get_c(tmp);
	while (tmp && tmp->next)
	{
		if (ft_get_c(tmp->next) < min)
			min = ft_get_c(tmp->next);
		tmp = tmp->next;
	}
	return (min);
}

int	ft_get_max(t_list *a)
{
	t_list	*tmp;
	int		max;

	tmp = a;
	max = ft_get_c(tmp);
	while (tmp && tmp->next)
	{
		if (ft_get_c(tmp->next) > max)
			max = ft_get_c(tmp->next);
		tmp = tmp->next;
	}
	return (max);
}

int	ft_find_position(int n, t_list *a)
{
	t_list	*tmp;
	int		pos;

	if (!a)
		return (0);
	tmp = a;
	if (ft_get_c(ft_lstlast(tmp)) < n && ft_get_c(tmp) > n)
		return (0);
	if (n < ft_get_min(a))
		return (ft_index(a, ft_get_min(a)));
	else if (n > ft_get_max(a))
	{
		if (ft_index(a, ft_get_max(a)) == ft_lstsize(a) - 1)
			return (0);
		return (ft_index(a, ft_get_max(a)) + 1);
	}
	pos = 1;
	while (tmp && tmp->next)
	{
		if (ft_get_c(tmp) < n && ft_get_c(tmp->next) > n)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	ft_get_c(t_list *a)
{
	return (*(int *)a->content);
}

void	ft_del(void *content)
{
	free(content);
}

t_stack	*ft_init_stack(char name)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->name = name;
	s->values = NULL;
	s->size = 0;
	return (s);
}
