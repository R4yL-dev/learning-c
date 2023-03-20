/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:17:01 by lray              #+#    #+#             */
/*   Updated: 2023/03/20 12:19:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libs/ft_printf.h"
# include "libs/ft_stack.h"
# include "libs/libft.h"

char	**args_init(int *argc, char *argv[]);
int		args_isvalid(int nbr_args, char *args[]);
int		args_isunique(int nbr_args, char *args[]);

int		*copy_array(int	*arr, int size);
void	apply_mask(int *arr, int *mask, int size);

void	radix(t_stack **stack_a, t_stack **stack_b);

void	sort2(t_stack **stack_a);

void	sort3(t_stack **stack_a);

void	sort5(t_stack **stack_a, t_stack **stack_b);

void	selection_sort(int *arr, int n);

void	exec_pa(t_stack **stack_a, t_stack **stack_b);
void	exec_pb(t_stack **stack_a, t_stack **stack_b);
void	exec_sa(t_stack **stack);
void	exec_ra(t_stack **stack);
void	exec_rra(t_stack **stack);

void	mv_swap(t_stack **stack);
void	mv_push(t_stack **stack1, t_stack **stack2);
void	mv_rotate(t_stack **stack);
void	mv_rrotate(t_stack **stack);

long	ft_atol(const char *nptr);
void	ft_puterror(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);

void	db_show_stack(t_stack **stack_a, t_stack **stack_b);
void	db_show_size(t_stack **stack_a, t_stack **stack_b);
void	db_show_result(t_stack **stack_a, t_stack **stack_b);

#endif
