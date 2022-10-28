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

void	ft_rotate(t_list **a, char direction, char *str)
{
	t_list	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	if (direction != 'r')
	{
		ft_lstadd_back(a, *a);
		tmp = (*a)->next;
		(*a)->next = NULL;
		*a = tmp;
	}
	else
	{
		tmp = *a;
		while (tmp->next != ft_lstlast(*a))
			tmp = tmp->next;
		ft_lstadd_front(a, ft_lstlast(*a));
		tmp->next = NULL;
	}
	ft_printf(str);
}

int	ft_get_c(t_list *a)
{
	return (*(int *)a->content);
}

void	ft_del(void *content)
{
	free(content);
}
