/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:58:16 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 12:01:47 by lorobert         ###   ########.fr       */
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
	int		size;
}	t_stack;

// Parse args
int		parse_args(int argc, char **argv, t_list **a, t_tab *sorted);
int		parse_string(char *s, t_list **a, t_tab *sorted);

// Error management
void	ft_error(t_stack *a, t_tab *t);
int		ft_check_duplicates(t_tab *tab);

// Movements
void	ft_swap(t_stack *s, int print);
void	ft_swap_both(t_stack *s1, t_stack *s2, int print);
void	ft_push(t_stack *s1, t_stack *s2);
void	ft_rotate(t_stack *s, int print);
void	ft_rotate_both(t_stack *s1, t_stack *s2, int print);
void	ft_rrotate(t_stack *s, int print);
void	ft_rrotate_both(t_stack *s1, t_stack *s2, int print);

// Stack manipulation
t_stack	*ft_init_stack(char name);
void	ft_clear_stack(t_stack *s);
int		ft_get_c(t_list *a);
int		ft_get_min(t_list *a);
int		ft_get_max(t_list *a);
void	ft_print_stack(t_list *a, t_list *b);

// Array manipulation
t_tab	*ft_init_tab(void);
void	ft_clear_tab(t_tab *t);
t_tab	*ft_sorted_chunks(t_tab *tab, t_stack *s);
int		ft_sorted_index(t_tab *tab, int n);
void	ft_sort_tab(t_tab *tab);

// Sorting
int		ft_is_sorted(t_list *a);
void	ft_sort(t_stack *a, t_tab *sorted);
void	ft_sort_3(t_stack *a);
void	ft_sort_small(t_stack *a, t_tab *sorted);
void	ft_sort_large(t_stack *a, t_tab *sorted);
void	ft_move_chunks(t_stack *a, t_stack *b, t_tab *chunks);
void	ft_move_last_chunk(t_stack *a, t_stack *b);
void	ft_move_back(t_stack *a, t_stack *b, t_tab *sorted, int *n_down);
int		ft_find_position(int n, t_list *a);
int		ft_find_rev_position(int n, t_list *a);
int		ft_index(t_list *a, int value);
int		ft_rev_index(t_list *a, int value);
int		ft_index_limit(t_list *a, int value);
int		ft_rev_index_limit(t_list *a, int value);

// Misc
int		ft_strslen(char **strs);
int		ft_min(int a, int b);
void	ft_del(void *content);

#endif
