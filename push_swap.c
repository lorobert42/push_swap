/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:58 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/20 13:19:02 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	parse_args(int argc, char **argv, t_list **a, t_tab *sorted)
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
		if (!*a)
			*a = ft_lstnew(content);
		else if (!(*a)->content)
			(*a)->content = content;
		else
			ft_lstadd_back(a, ft_lstnew(content));
		sorted->tab[i] = tmp;
		i++;
	}
	ft_sort_tab(sorted);
	return (i);
}

int	parse_string(char *s, t_list **a, t_tab *sorted)
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
		if (!*a)
			*a = ft_lstnew(content);
		else if (!(*a)->content)
			(*a)->content = content;
		else
			ft_lstadd_back(a, ft_lstnew(content));
		sorted->tab[i] = tmp;
		i++;
	}
	ft_sort_tab(sorted);
	return (i);
}

void	ft_error(t_stack *s, t_tab *t)
{
	write(2, "Error\n", 6);
	if (s)
	{
		ft_lstclear(&(s->values), &ft_del);
		free(s);
	}
	if (t->tab)
		free(t->tab);
	exit(0);
}

int	ft_check_duplicates(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size - 1)
	{
		if (tab->tab[i] == tab->tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_tab	sorted;

	if (argc == 1)
		return (0);
	a = ft_init_stack('a');
	if (!a)
		ft_error(NULL, &sorted);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a->size = parse_string(argv[1], &a->values, &sorted);
	else
		a->size = parse_args(argc, argv, &a->values, &sorted);
	if (!a->size)
		ft_error(a, &sorted);
	if (ft_check_duplicates(&sorted))
		ft_error(a, &sorted);
	ft_sort(a, &sorted);
	ft_lstclear(&(a->values), &ft_del);
	free(a);
	free(sorted.tab);
	return (0);
}
