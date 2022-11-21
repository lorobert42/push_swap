/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:40:32 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 09:41:37 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_tab(t_tab *t)
{
	int	i;

	i = 0;
	while (i < t->size)
	{
		ft_printf("%d", t->tab[i]);
		if (i < t->size - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("\n");
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