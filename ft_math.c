/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:28 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/19 16:18:25 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_index_limit(t_list *a, int value)
{
	int	index;

	index = 0;
	while (a)
	{
		if (ft_get_c(a) <= value)
			return (index);
		a = a->next;
		index++;
	}
	return (-1);
}

int	ft_rev_index_limit(t_list *a, int value)
{
	t_list	*tmp;
	int		index;
	int		i;

	tmp = a;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) <= value)
			index = i;
		tmp = tmp->next;
		i++;
	}
	return (ft_lstsize(a) - index);
}

int	ft_index(t_list *a, int value)
{
	t_list	*tmp;
	int		index;

	tmp = a;
	index = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

int	ft_rev_index(t_list *a, int value)
{
	t_list	*tmp;
	int		index;
	int		i;

	tmp = a;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (ft_get_c(tmp) == value)
			index = i;
		tmp = tmp->next;
		i++;
	}
	return (ft_lstsize(a) - index);
}

t_tab	*ft_sorted_chunks(t_tab *tab, t_stack *s)
{
	t_tab	*chunks;
	int		i;

	chunks = malloc(sizeof(t_tab));
	if (!chunks)
		return (NULL);
	if (ft_lstsize(s->values) <= 100)
		chunks->size = 3;
	else
		chunks->size = 9;
	chunks->tab = malloc(sizeof(int) * chunks->size);
	if (!chunks->tab)
		return (NULL);
	i = 0;
	while (i < chunks->size)
	{
		chunks->tab[i] = tab->tab[tab->size / (chunks->size + 1) \
			+ i * tab->size / (chunks->size + 1) - 1];
		i++;
	}
	return (chunks);
}

int	ft_sorted_index(t_tab *tab, int n)
{
	int	i;

	i = 0;
	while (i < tab->size)
	{
		if (tab->tab[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_sort_tab(t_tab *tab)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < tab->size)
	{
		j = i;
		while (j > 0 && tab->tab[j - 1] > tab->tab[j])
		{
			temp = tab->tab[j];
			tab->tab[j] = tab->tab[j - 1];
			tab->tab[j - 1] = temp;
			j--;
		}
		i++;
	}
}
