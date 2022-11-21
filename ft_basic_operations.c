/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:27:17 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 09:33:37 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	s1->size++;
	s2->size--;
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
