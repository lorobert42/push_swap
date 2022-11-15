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

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static int	parse_args(int argc, char **argv, t_list **a, t_tab *sorted)
{
	int	i;
	int	tmp;
	int	*content;

	sorted->tab = malloc(sizeof(int) * (argc - 1));
	sorted->size = argc - 1;
	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (ft_strncmp(ft_itoa(tmp), argv[i + 1], ft_strlen(argv[i + 1])))
			return (0);
		content = malloc(sizeof(int));
		*content = tmp;
		if (!(*a)->content)
			(*a)->content = content;
		else
			ft_lstadd_back(a, ft_lstnew(content));
		sorted->tab[i] = tmp;
		i++;
	}
	ft_sort_tab(sorted);
	return (i);
}

static int	parse_string(char *s, t_list **a, t_tab *sorted)
{
	int		i;
	char	**strs;
	int		tmp;
	int		*content;

	strs = ft_split(s, ' ');
	i = 0;
	while (strs[i++])
		continue ;
	sorted->tab = malloc(sizeof(int) * (i));
	sorted->size = i;
	i = 0;
	while (strs[i])
	{
		tmp = ft_atoi(strs[i]);
		if (ft_strncmp(ft_itoa(tmp), strs[i], ft_strlen(strs[i])))
			return (0);
		content = malloc(sizeof(int));
		*content = tmp;
		if (!(*a)->content)
			(*a)->content = content;
		else
			ft_lstadd_back(a, ft_lstnew(content));
		sorted->tab[i] = tmp;
		i++;
	}
	ft_sort_tab(sorted);
	return (i);
}

void	ft_error(t_list **a)
{
	write(2, "Error\n", 6);
	if (a)
		ft_lstclear(a, &ft_del);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_tab 	sorted;
	int		len;

	if (argc == 1)
		ft_error(NULL);
	a = ft_lstnew(NULL);
	if (!a)
		ft_error(NULL);
	sorted.size = 0;
	sorted.tab = NULL;
	if (argc == 2 && ft_strchr(argv[1], ' '))
		len = parse_string(argv[1], &a, &sorted);
	else
		len = parse_args(argc, argv, &a, &sorted);
	if (!len)
		ft_error(&a);
	ft_sort(&a, len, &sorted);
	ft_lstclear(&a, &ft_del);
	return (0);
}
