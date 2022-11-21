/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:52:35 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 12:02:42 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_tab	*ft_init_tab(void)
{
	t_tab	*t;

	t = malloc(sizeof(t_tab));
	if (!t)
		return (NULL);
	t->size = 0;
	t->tab = NULL;
	return (t);
}

void	ft_clear_tab(t_tab *t)
{
	if (!t)
		return ;
	free(t->tab);
	free(t);
}
