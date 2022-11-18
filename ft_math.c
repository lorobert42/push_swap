/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/27 15:19:51 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_index_limit(t_list *a, int value)
{
	int 	index;

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
	int 	index;
	int 	i;

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
	int 	index;

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
	int 	index;
	int 	i;

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

int	ft_sorted_index(int n, t_tab *tab)
{
	int i;

	i = 0;
	while ( i < tab->size)
	{
		if (tab->tab[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_sorted_median(t_tab *tab)
{
	return (tab->tab[tab->size / 2]);
}

t_tab	*ft_sorted_chunks(t_tab *tab)
{
	//TODO: use div instead of ideal_size
	t_tab	*chunks;
	int		i;
	int		ideal_size;

	ideal_size = 25;
	chunks = malloc(sizeof(t_tab));
	chunks->size = tab->size / ideal_size - 1;
	if (chunks->size < 2)
	{
		chunks->size = 0;
		chunks->tab = NULL;
		return (chunks);
	}
	chunks->tab = malloc(sizeof(int) * chunks->size);
	if (!chunks->tab)
		return (NULL);
	i = 0;
	while (i < chunks->size)
	{
		if (i * ideal_size + ideal_size >= tab->size)
			chunks->tab[i] = tab->tab[tab->size - 1];
		chunks->tab[i] = tab->tab[i * ideal_size + ideal_size];
		i++;
	}
	return (chunks);
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