/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:13:29 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 17:13:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_isvalid(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	args_isunique(int argc, char *argv[])
{
	int	i;
	int	j;
	int	arg_to_int;

	i = 1;
	while (i < argc)
	{
		arg_to_int = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			if (arg_to_int == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
