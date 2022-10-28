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

void	ft_sort(t_list **a, int len);
int		get_c(t_list *a);
void	ft_del(void *content);
void	ft_error(t_list **a);
void	ft_swap(t_list **a, char *str);
void	ft_push(t_list **a, t_list **b, char *str);
void	ft_rotate(t_list **a, char direction, char *str);

#endif
