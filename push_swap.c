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

static int	*parse_args(int argc, char **argv)
{
	int	*a;
	int	i;

	a = malloc(sizeof(int) * (argc - 1));
	if (!a)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		a[i] = ft_atoi(argv[i + 1]);
		if (ft_strncmp(ft_itoa(a[i]), argv[i + 1], ft_strlen(argv[i + 1])))
			return (NULL);
		i++;
	}
	return (a);
}

static int	*parse_string(char *s, int *len)
{
	int		*a;
	int		i;
	char	**strs;

	strs = ft_split(s, ' ');
	i = 0;
	while (strs[i])
		i++;
	*len = i;
	a = malloc(sizeof(int) * i);
	if (!a)
		return (NULL);
	i--;
	while (i >= 0)
	{
		a[i] = ft_atoi(strs[i]);
		if (ft_strncmp(ft_itoa(a[i]), strs[i], ft_strlen(strs[i])))
			return (NULL);
		i--;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	len;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	len = argc - 1;
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = parse_string(argv[1], &len);
	else
		a = parse_args(argc, argv);
	if (!a)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_sort(a, len);
	free(a);
	return (0);
}
