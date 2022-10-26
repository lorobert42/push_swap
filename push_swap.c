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

void	ft_sort(int **a, int len)
{
	int	**b;

	b = malloc(sizeof(int) * len);
	if (!b)
		return ;
	while (1)
	{
		if (*a[0] < *a[1])
			ft_swap(a);
		else
			ft_move(a, b);
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	i;

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
	i = 0;
	while (i < argc - 1)
	{
		printf("%d\n", a[i]);
		i++;
	}
	free(a);
}
