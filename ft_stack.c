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

void	ft_swap(t_stack *s, int print)
{
	t_list	*tmp;

	if (ft_lstsize(s->values) < 2)
		return ;
	tmp = s->values;
	s->values = s->values->next;
	tmp->next = s->values->next;
	s->values->next = tmp;
	if (print)
		ft_printf("s%c\n", s->name);
}

void	ft_swap_both(t_stack *s1, t_stack *s2)
{
	ft_swap(s1, 0);
	ft_swap(s2, 0);
	ft_printf("ss\n");
}

void	ft_push(t_stack *s1, t_stack *s2)
{
	t_list	*tmp;

	if (!s2->values)
		return ;
	if (!s1->values)
	{
		s1->values = s2->values;
		s2->values = s2->values->next;
		s1->values->next = NULL;
	}
	else
	{
		tmp = s2->values->next;
		ft_lstadd_front(&(s1->values), s2->values);
		s2->values = tmp;
	}
	ft_printf("p%c\n", s1->name);
}

void	ft_rotate(t_stack *s, int print)
{
	t_list	*tmp;

	if (ft_lstsize(s->values) < 2)
		return ;
	ft_lstadd_back(&(s->values), s->values);
	tmp = s->values->next;
	s->values->next = NULL;
	s->values = tmp;
	if (print)
		ft_printf("r%c\n", s->name);
}

void	ft_rotate_both(t_stack *s1, t_stack *s2)
{
	ft_rotate(s1, 0);
	ft_rotate(s2, 0);
	ft_printf("rr\n");
}

void	ft_rrotate(t_stack *s, int print)
{
	t_list	*tmp;

	if (ft_lstsize(s->values) < 2)
		return ;
	tmp = s->values;
	while (tmp->next != ft_lstlast(s->values))
		tmp = tmp->next;
	ft_lstadd_front(&(s->values), ft_lstlast(s->values));
	tmp->next = NULL;
	if (print)
		ft_printf("rr%c\n", s->name);
}

void	ft_rrotate_both(t_stack *s1, t_stack *s2)
{
	ft_rrotate(s1, 0);
	ft_rrotate(s2, 0);
	ft_printf("rrr\n");
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

int ft_find_rev_position(int n, t_list *a)
{
	int 	pos;

	if (!a || ft_lstsize(a) == 1)
		return (0);
	if (n < ft_get_min(a))
		return (ft_index(a, ft_get_max(a)) % ft_lstsize(a));
	if (n > ft_get_max(a))
		return (ft_index(a, ft_get_min(a)));
	if (ft_get_c(a) < n && ft_get_c(ft_lstlast(a)) > n)
		return (0);
	pos = 1;
	while (a && a->next)
	{
		if (ft_get_c(a) > n && ft_get_c(a->next) < n)
			return (pos);
		a = a->next;
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
