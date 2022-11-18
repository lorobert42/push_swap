/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/27 15:19:51 by lorobert         ###   ########.fr       */
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

void	ft_print_stack(t_list *a, t_list *b)
{
	int	size;
	int	i;

	if (ft_lstsize(a) >= ft_lstsize(b))
		size = ft_lstsize(a);
	else
		size = ft_lstsize(b);
	i = 0;
	ft_printf("-- STACK STATE --\n");
	while (i < size)
	{
		if (!a)
			ft_printf("-\t\t\t\t%d\n", ft_get_c(b));
		else if (!b)
			ft_printf("%d\t\t\t\t-\n", ft_get_c(a));
		else
			ft_printf("%d\t\t\t\t%d\n", ft_get_c(a), ft_get_c(b));
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		i++;
	}
	ft_printf("-- END --\n");
}
