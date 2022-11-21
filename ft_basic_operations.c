/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:27:17 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 13:52:57 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *s, int print)
{
	t_list	*tmp;

	if (ft_lstsize(s->list) < 2)
		return ;
	tmp = s->list;
	s->list = s->list->next;
	tmp->next = s->list->next;
	s->list->next = tmp;
	if (print)
		ft_printf("s%c\n", s->name);
}

void	ft_push(t_stack *s1, t_stack *s2, int print)
{
	t_list	*tmp;

	if (!s2->list)
		return ;
	if (!s1->list)
	{
		s1->list = s2->list;
		s2->list = s2->list->next;
		s1->list->next = NULL;
	}
	else
	{
		tmp = s2->list->next;
		ft_lstadd_front(&(s1->list), s2->list);
		s2->list = tmp;
	}
	s1->size++;
	s2->size--;
	if (print)
		ft_printf("p%c\n", s1->name);
}

void	ft_rotate(t_stack *s, int print)
{
	t_list	*tmp;

	if (ft_lstsize(s->list) < 2)
		return ;
	ft_lstadd_back(&(s->list), s->list);
	tmp = s->list->next;
	s->list->next = NULL;
	s->list = tmp;
	if (print)
		ft_printf("r%c\n", s->name);
}

void	ft_rrotate(t_stack *s, int print)
{
	t_list	*tmp;

	if (ft_lstsize(s->list) < 2)
		return ;
	tmp = s->list;
	while (tmp->next != ft_lstlast(s->list))
		tmp = tmp->next;
	ft_lstadd_front(&(s->list), ft_lstlast(s->list));
	tmp->next = NULL;
	if (print)
		ft_printf("rr%c\n", s->name);
}
