/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:01:24 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/19 14:12:58 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_tab	sorted;
	int		len;
	char	*instruction;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	if (!a)
		ft_error(NULL, &sorted);
	a->values = ft_lstnew(NULL);
	if (!a->values)
		ft_error(NULL, &sorted);
	a->name = 'a';
	sorted.size = 0;
	sorted.tab = NULL;
	if (argc == 2 && ft_strchr(argv[1], ' '))
		len = parse_string(argv[1], a->values, &sorted);
	else
		len = parse_args(argc, argv, a->values, &sorted);
	if (!len)
		ft_error(a, &sorted);
	if (ft_check_duplicates(&sorted))
		ft_error(a, &sorted);
	instruction = get_next_line(1);
	while (instruction)
	{
		ft_execute(instruction);
		instruction = get_next_line(1);
	}
	ft_lstclear(&(a->values), &ft_del);
	free(a);
	free(sorted.tab);
	return (0);
}