/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:58 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/26 14:54:48 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "push_swap.h"

int ft_is_sorted(int *a, int len)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (i < len)
	{
		if (a[i] < max)
			return (0);
		max = a[i];
		i++;
	}
	return (1);
}

void    ft_sort_3(int *a, int len)
{
    if (ft_is_sorted(a, len))
        return ;
	if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
		ft_printf("sa\nra\n");
	else if (a[0] > a[1] && a[0] < a[2] && a[1] < a[2])
		ft_printf("sa\n");
	else if (a[0] < a[1] && a[0] > a[2] && a[1] > a[2])
		ft_printf("rra\n");
	else if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		ft_printf("ra\n");
	else if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
		ft_printf("sa\nrra\n");
}

void	ft_sort(int *a, int len)
{
	int	**b;

    if (len == 1)
        return ;
    else if (len == 2)
    {
        if (a[0] > a[1])
            ft_printf("sa\n");
        return ;
    }
    else if (len == 3)
        return (ft_sort_3(a, len));
	b = malloc(sizeof(int) * len);
	if (!b)
		return ;
}

int	main(int argc, char **argv)
{
	int	*a;
	int	i;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	a = malloc(sizeof(int) * (argc - 1));
	if (!a)
	{
		printf("Error\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ft_sort(a, argc - 1);
	free(a);
	return (0);
}
