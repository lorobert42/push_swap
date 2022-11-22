/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:45:29 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 13:45:51 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	parse_args(int argc, char **argv, t_list **a, t_tab *sorted)
{
	int	i;
	int	*content;

	sorted->tab = malloc(sizeof(int) * (argc - 1));
	sorted->size = argc - 1;
	i = 0;
	while (i < argc - 1)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(argv[i + 1]);
		if (ft_strncmp(ft_itoa(*content), argv[i + 1], ft_strlen(argv[i + 1])))
			return (0);
		if (!*a)
			*a = ft_lstnew(content);
		else
			ft_lstadd_back(a, ft_lstnew(content));
		sorted->tab[i] = *content;
		i++;
	}
	ft_sort_tab(sorted);
	return (i);
}

int	parse_string(char *s, t_list **a, t_tab *sorted)
{
	int		i;
	char	**strs;
	int		*content;

	strs = ft_split(s, ' ');
	i = ft_strslen(strs);
	sorted->tab = malloc(sizeof(int) * (i));
	sorted->size = i;
	i = 0;
	while (strs[i])
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(strs[i]);
		if (ft_strncmp(ft_itoa(*content), strs[i], ft_strlen(strs[i])))
			return (0);
		if (!*a)
			*a = ft_lstnew(content);
		else
			ft_lstadd_back(a, ft_lstnew(content));
		sorted->tab[i] = *content;
		i++;
	}
	ft_sort_tab(sorted);
	return (i);
}