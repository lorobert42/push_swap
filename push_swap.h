/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:58:16 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:21:13 by lorobert         ###   ########.fr       */
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
	t_list	*list;
	int		size;
}	t_stack;

typedef struct s_chunk
{
	int	mid;
	int	mid_i;
	int	size;
	int	start;
	int	start_i;
	int	end;
	int	end_i;
}	t_chunk;

// Parse args
int		parse_args(int argc, char **argv, t_list **a, t_tab *goal);
int		parse_string(char *s, t_list **a, t_tab *goal);

// Error management
void	ft_error(t_stack *a, t_tab *t);
int		ft_check_duplicates(t_tab *t);

// Movements
void	ft_swap(t_stack *s, int print);
void	ft_swap_both(t_stack *s1, t_stack *s2, int print);
void	ft_push(t_stack *s1, t_stack *s2, int print);
void	ft_rotate(t_stack *s, int print);
void	ft_rotate_both(t_stack *s1, t_stack *s2, int print);
void	ft_rrotate(t_stack *s, int print);
void	ft_rrotate_both(t_stack *s1, t_stack *s2, int print);

// Stack manipulation
t_stack	*ft_init_stack(char name);
void	ft_clear_stack(t_stack *s);
int		ft_get_c(t_list *l);
int		ft_get_min(t_stack *s);
int		ft_get_max(t_stack *s);
void	ft_print_stack(t_list *a, t_list *b);

// Array manipulation
t_tab	*ft_init_tab(void);
void	ft_clear_tab(t_tab *t);
t_chunk	*ft_chunks(t_stack *s, t_tab *goal);
void	ft_update_chunk(t_chunk *chunk, t_tab *goal);
int		ft_sorted_index(t_tab *goal, int n);
void	ft_sort_tab(t_tab *t);
void	ft_print_tab(t_tab *t);

// Sorting
int		ft_is_sorted(t_stack *s);
void	ft_sort(t_stack *a, t_tab *goal);
void	ft_sort_3(t_stack *a);
void	ft_sort_small(t_stack *a, t_tab *goal);
void	ft_sort_large(t_stack *a, t_tab *goal);
void	ft_move_chunks(t_stack *a, t_stack *b, t_tab *goal, t_chunk *chunks);
void	ft_move_back(t_stack *a, t_stack *b, t_tab *goal, int *n_down);
int		ft_find_between(t_stack *s, int min, int max);
int		ft_index(t_stack *s, int value);
int		ft_rev_index(t_list *s, int value);
int		ft_index_limit(t_list *l, int min, int max);
int		ft_rev_index_limit(t_list *l, int min, int max);

// Misc
int		ft_strslen(char **strs);
int		ft_min(int a, int b);
void	ft_del(void *content);

#endif
