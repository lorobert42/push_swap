/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:58 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 14:05:02 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_tab	*sorted;

	if (argc == 1)
		return (0);
	sorted = ft_init_tab();
	a = ft_init_stack('a');
	if (!a)
		ft_error(NULL, NULL, sorted, "Error\n");
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a->size = parse_string(argv[1], &a->list, sorted);
	else
		a->size = parse_args(argc, argv, &a->list, sorted);
	if (!a->size)
		ft_error(a, NULL, sorted, "Error\n");
	if (ft_check_duplicates(sorted))
		ft_error(a, NULL, sorted, "Error\n");
	ft_sort(a, sorted);
	ft_clear_all(a, NULL, sorted);
	return (0);
}
