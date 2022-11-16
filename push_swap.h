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

typedef struct s_stack {
	char	name;
	t_list	*values;
} t_stack;

void	ft_sort(t_stack *a, int len, t_tab *sorted);
int		ft_get_c(t_list *a);
int		ft_min(int a, int b);
int		ft_get_min(t_list *a);
int 	ft_get_max(t_list *a);
void	ft_del(void *content);
void	ft_error(t_stack *a);
void	ft_swap(t_stack *s, int print);
void	ft_swap_both(t_stack *s1, t_stack *s2);
void	ft_push(t_stack *s1, t_stack *s2);
void	ft_rotate(t_stack *s, int print);
void	ft_rotate_both(t_stack *s1, t_stack *s2);
void	ft_rrotate(t_stack *s, int print);
void	ft_rrotate_both(t_stack *s1, t_stack *s2);
int 	ft_find_position(int n, t_list *a);
int		ft_stack_median(t_tab *tab);
int		ft_index(t_list *a, int value);
int		ft_rev_index(t_list *a, int value);
int		ft_sorted_index(int n, t_tab *tab);
void	ft_sort_tab(t_tab *tab);
void	ft_print_stack(t_list *a, t_list *b);

#endif
