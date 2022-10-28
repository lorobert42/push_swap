/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:58:16 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/26 13:00:19 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_tab {
	int *tab;
	int size;
} t_tab;

void	ft_sort(t_list **a, int len, t_tab *sorted);
int		ft_get_c(t_list *a);
void	ft_del(void *content);
void	ft_error(t_list **a);
void	ft_swap(t_list **a, char *str);
void	ft_push(t_list **a, t_list **b, char *str);
void	ft_rotate(t_list **a, char direction, char *str);
int		ft_stack_mean(t_list **a);
int		ft_stack_median(t_tab *tab);
int		ft_half_sorted(t_list **a, int mean);
int		ft_is_below(t_list **a, int threshold);
int		ft_is_above(t_list **a, int threshold);
int		ft_get_front_index(t_list **a, int threshold);
int		ft_get_back_index(t_list **a, int threshold);
void	ft_sort_tab(t_tab *tab);

#endif
