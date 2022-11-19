/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:58:16 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/19 15:34:27 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_tab {
	int	*tab;
	int	size;
}	t_tab;

typedef struct s_stack {
	char	name;
	t_list	*values;
}	t_stack;

// Parse args
int		parse_args(int argc, char **argv, t_list *a, t_tab *sorted);
int		parse_string(char *s, t_list *a, t_tab *sorted);

// Error management
void	ft_error(t_stack *a, t_tab *t);
int		ft_check_duplicates(t_tab *tab);

// Movements
void	ft_swap(t_stack *s, int print);
void	ft_swap_both(t_stack *s1, t_stack *s2);
void	ft_push(t_stack *s1, t_stack *s2);
void	ft_rotate(t_stack *s, int print);
void	ft_rotate_both(t_stack *s1, t_stack *s2);
void	ft_rrotate(t_stack *s, int print);
void	ft_rrotate_both(t_stack *s1, t_stack *s2);

// Stack manipulation
int		ft_get_c(t_list *a);
int		ft_get_min(t_list *a);
int		ft_get_max(t_list *a);
void	ft_print_stack(t_list *a, t_list *b);

// Array manipulation
t_tab	*ft_sorted_chunks(t_tab *tab, t_stack *s);
int		ft_sorted_index(t_tab *tab, int n);
void	ft_sort_tab(t_tab *tab);

// Sorting
void	ft_sort(t_stack *a, int len, t_tab *sorted);
int		ft_find_position(int n, t_list *a);
int		ft_find_rev_position(int n, t_list *a);
int		ft_index(t_list *a, int value);
int		ft_rev_index(t_list *a, int value);
int		ft_index_limit(t_list *a, int value);
int		ft_rev_index_limit(t_list *a, int value);

// Misc
int		ft_min(int a, int b);
void	ft_del(void *content);

#endif
