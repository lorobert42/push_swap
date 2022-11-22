/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:13:59 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:17:07 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

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

void	ft_del(void *content)
{
	free(content);
}

void	ft_clear_stack(t_stack *s)
{
	if (!s)
		return ;
	ft_lstclear(&(s->list), &ft_del);
	free(s);
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
