/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:45:29 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/23 10:27:12 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	verif_overflow(int parsed, char *nbr)
{
	char	*verif;

	verif = ft_itoa(parsed);
	if (ft_strncmp(verif, nbr, ft_strlen(nbr)))
	{
		free(verif);
		return (0);
	}
	free(verif);
	return (1);
}

int	parse_args(int argc, char **argv, t_list **a, t_tab *sorted)
{
	int		i;
	int		*content;

	sorted->tab = malloc(sizeof(int) * (argc - 1));
	sorted->size = argc - 1;
	i = 0;
	while (i < argc - 1)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(argv[i + 1]);
		if (!verif_overflow(*content, argv[i + 1]))
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

static void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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
		if (!verif_overflow(*content, strs[i]))
			return (0);
		if (!*a)
			*a = ft_lstnew(content);
		else
			ft_lstadd_back(a, ft_lstnew(content));
		sorted->tab[i] = *content;
		i++;
	}
	ft_sort_tab(sorted);
	free_strs(strs);
	return (i);
}
