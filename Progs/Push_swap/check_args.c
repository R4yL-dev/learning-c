/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:42:12 by lray              #+#    #+#             */
/*   Updated: 2023/03/05 23:44:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char *argv[])
{

	if (!is_valid_args(argc, argv))
		return (0);
	if (!only_unique_args(argc, argv))
		return (0);
	return (1);
}

int	is_valid_args(int argc, char *argv[])
{
	int	i;

	while (argc > 0)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (i == 0 && argv[argc][i] == '-')
				i++;
			if (!ft_isdigit(argv[argc][i]))
				return (0);
			i++;
		}
		if (ft_atol(argv[argc]) > INT_MAX || ft_atol(argv[argc]) < INT_MIN)
			return (0);
		argc--;
	}
	return (1);
}

int	only_unique_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = argc;
	j = i - 1;
	while (i > 0)
	{
		while (j >= 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j--;
		}
		i--;
		j = i - 1;
	}
	return (1);
}
