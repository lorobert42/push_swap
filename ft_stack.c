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

void	ft_swap(t_list **a, char *str)
{
	t_list	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_printf(str);
}

void	ft_push(t_list **a, t_list **b, char *str)
{
	t_list	*tmp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		tmp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = tmp;
	}
	ft_printf(str);
}

void	ft_rotate(t_list **a, char *str)
{
	t_list	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	ft_lstadd_back(a, *a);
	tmp = (*a)->next;
	(*a)->next = NULL;
	*a = tmp;
	ft_printf(str);
}

void	ft_rrotate(t_list **a, char *str)
{
	t_list	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next != ft_lstlast(*a))
		tmp = tmp->next;
	ft_lstadd_front(a, ft_lstlast(*a));
	tmp->next = NULL;
	ft_printf(str);
}

int ft_get_min(t_list *a)
{
	t_list *tmp;
	int 	min;

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

int ft_get_max(t_list *a)
{
	t_list *tmp;
	int 	max;

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

int ft_find_position(int n, t_list *a)
{
	t_list	*tmp;
	int 	pos;

	if (!a)
		return (0);
	tmp = a;
	pos = 0;
	if (ft_get_c(ft_lstlast(tmp)) < n && ft_get_c(tmp) > n)
		return (0);
	if (n < ft_get_min(a) || n > ft_get_max(a))
		return (ft_min(ft_index(&a, ft_get_min(a)), ft_index(&a, ft_get_max(a))));
	while (tmp && tmp->next)
	{
		if (ft_get_c(tmp) > n && ft_get_c(tmp->next) < n)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (ft_lstsize(a) - 1);
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
	int size;
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
			ft_printf("-\t\t%d\n", ft_get_c(b));
		else if (!b)
			ft_printf("%d\t\t-\n", ft_get_c(a));
		else
			ft_printf("%d\t\t%d\n", ft_get_c(a), ft_get_c(b));
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		i++;
	}
	ft_printf("-- END --\n");
}
