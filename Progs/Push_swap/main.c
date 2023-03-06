/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:09:05 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 20:18:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(int nbr_args, char *args[]);
static int	*convert_args(int nbr_args, char *args[]);
static void	sanitize(int nbr_args, int *args);
static void	args_to_stack(t_stack **stack, int nbr_args, int *args);

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*args_int;

	if (argc == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	/* if (argc == 2)
		argv = ft_split((const char *) argv[1], ' '); */
	if (!check_args(argc, argv))
		ft_puterror(&stack_a, &stack_b);
	args_int = convert_args(argc, argv);
	argc--;
	sanitize(argc, args_int);
	args_to_stack(&stack_a, argc, args_int);
	radix(&stack_a, &stack_b);
	free(args_int);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}

static int	check_args(int nbr_args, char *args[])
{
	if (!args_isvalid(nbr_args, args) || !args_isunique(nbr_args, args))
		return (0);
	return (1);
}

static int	*convert_args(int nbr_args, char *args[])
{
	int	*resp;
	int	i;

	resp = malloc(sizeof(int) * (nbr_args - 1));
	if (!resp)
		return (NULL);
	i = 1;
	while (i < nbr_args)
	{
		resp[i - 1] = ft_atoi(args[i]);
		i++;
	}
	return (resp);
}

static void	sanitize(int nbr_args, int *args)
{
	int	*copy;

	copy = copy_array(args, nbr_args);
	selection_sort(copy, nbr_args);
	apply_mask(args, copy, nbr_args);
}

static void	args_to_stack(t_stack **stack, int nbr_args, int *args)
{
	int	i;

	i = (nbr_args - 1);
	while (i >= 0)
	{
		ft_stkpush(stack, args[i]);
		i--;
	}
}
