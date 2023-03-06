/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:17:01 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 02:48:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libs/ft_printf.h"
# include "libs/ft_stack.h"
# include "libs/libft.h"


void	try_sort(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);

int		check_args(int argc, char *argv[]);
int		is_valid_args(int argc, char *argv[]);
int		only_unique_args(int argc, char *argv[]);

int		*sanitize(int argc, char *argv[]);

void	mv_swap(t_stack **stack);
void	mv_push(t_stack **stack1, t_stack **stack2);
void	mv_rotate(t_stack **stack);
void	mv_rrotate(t_stack **stack);

long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
void	ft_puterror(t_stack **stack_a, t_stack **stack_b);

void	db_show_stack(t_stack **stack_a, t_stack **stack_b);
void	db_show_size(t_stack **stack_a, t_stack **stack_b);
void	db_show_result(t_stack **stack_a, t_stack **stack_b);

#endif
