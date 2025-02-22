/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:27:36 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 11:23:55 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_both(t_stack *s1, t_stack *s2, int print)
{
	ft_swap(s1, 0);
	ft_swap(s2, 0);
	if (print)
		ft_printf("ss\n");
}

void	ft_rotate_both(t_stack *s1, t_stack *s2, int print)
{
	ft_rotate(s1, 0);
	ft_rotate(s2, 0);
	if (print)
		ft_printf("rr\n");
}

void	ft_rrotate_both(t_stack *s1, t_stack *s2, int print)
{
	ft_rrotate(s1, 0);
	ft_rrotate(s2, 0);
	if (print)
		ft_printf("rrr\n");
}
