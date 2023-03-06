/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:09:05 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 17:16:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(int argc, char *argv[]);
static int	*convert_args(int argc, char *argv[]);
static void	sanitize(int argc, int *argv);
static void	args_to_stack(t_stack **stack, int argc, int *argv);

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*args_int;

	if (argc == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_args(argc, argv))
		ft_puterror(&stack_a, &stack_b);
	args_int = convert_args(argc, argv);
	argc--;
	sanitize(argc, args_int);
	args_to_stack(&stack_a, argc, args_int);
	try_sort(&stack_a, &stack_b);
	free(args_int);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}

static int	check_args(int argc, char *argv[])
{
	if (!args_isvalid(argc, argv) || !args_isunique(argc, argv))
		return (0);
	return (1);
}

static int	*convert_args(int argc, char *argv[])
{
	int	*resp;
	int	i;

	resp = malloc(sizeof(int) * (argc - 1));
	if (!resp)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		resp[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (resp);
}

static void	sanitize(int argc, int *argv)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = malloc(sizeof(int) * argc);
	if (!tmp)
		return ;
	i = 0;
	while (i < argc)
	{
		tmp[i] = argv[i];
		i++;
	}
	sort_array(tmp, argc);
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (argv[i] == tmp[j])
				argv[i] = j;
			++j;
		}
		++i;
	}
	free(tmp);
}

static void	args_to_stack(t_stack **stack, int argc, int *argv)
{
	int		i;

	i = (argc - 1);
	while (i >= 0)
	{
		ft_stkpush(stack, argv[i]);
		i--;
	}
}
