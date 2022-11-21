/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 14:12:00 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

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

int	ft_find_position(t_stack *a, int n)
{
	t_list	*tmp;
	int		pos;

	tmp = a->list;
	if (!tmp)
		return (0);
	if (ft_get_c(ft_lstlast(tmp)) < n && ft_get_c(tmp) > n)
		return (0);
	if (n < ft_get_min(a))
		return (ft_index(a, ft_get_min(a)));
	else if (n > ft_get_max(a))
	{
		if (ft_index(a, ft_get_max(a)) == a->size - 1)
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
	s->list = NULL;
	s->size = 0;
	return (s);
}

void	ft_clear_stack(t_stack *s)
{
	if (!s)
		return ;
	ft_lstclear(&(s->list), &ft_del);
	free(s);
}
