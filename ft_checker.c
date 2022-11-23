/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:01:24 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/23 10:22:18 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "get_next_line.h"

int	ft_execute(char *command, t_stack *a, t_stack *b)
{
	if (ft_strncmp(command, "pa\n", 3) == 0)
		ft_push(a, b, 0);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		ft_push(b, a, 0);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ft_rotate(a, 0);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		ft_rotate(b, 0);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		ft_rotate_both(a, b, 0);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		ft_rrotate(a, 0);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		ft_rrotate(b, 0);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		ft_rrotate_both(a, b, 0);
	else if (ft_strncmp(command, "sa\n", 3) == 0)
		ft_swap(a, 0);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		ft_swap(b, 0);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ft_swap_both(a, b, 0);
	else
		return (1);
	return (0);
}

static void	init(t_tab **sorted, t_stack **a, t_stack **b)
{
	*sorted = ft_init_tab();
	*a = ft_init_stack('a');
	if (!*a)
		ft_error(NULL, NULL, *sorted, "Error\n");
	*b = ft_init_stack('b');
	if (!*b)
		ft_error(*a, NULL, *sorted, "Error\n");
}

static void	read_commands(t_stack *a, t_stack *b, t_tab *sorted)
{
	char	*command;

	command = get_next_line(1);
	while (command)
	{
		if (ft_execute(command, a, b))
			ft_error(a, b, sorted, "Error\n");
		command = get_next_line(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_tab	*sorted;

	if (argc == 1)
		return (0);
	init(&sorted, &a, &b);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a->size = parse_string(argv[1], &a->list, sorted);
	else
		a->size = parse_args(argc, argv, &a->list, sorted);
	if (!a->size)
		ft_error(a, b, sorted, "Error\n");
	if (ft_check_duplicates(sorted))
		ft_error(a, b, sorted, "Error\n");
	read_commands(a, b, sorted);
	if (ft_is_sorted(a))
		ft_printf("OK\n");
	else
		ft_error(a, b, sorted, "KO\n");
	ft_clear_all(a, b, sorted);
	return (0);
}
