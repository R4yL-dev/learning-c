/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:13:29 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 18:23:56 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_isvalid(int nbr_args, char *args[])
{
	int	i;
	int	j;

	i = 1;
	while (i < nbr_args)
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	args_isunique(int nbr_args, char *args[])
{
	int	i;
	int	j;
	int	arg_to_int;

	i = 1;
	while (i < nbr_args)
	{
		arg_to_int = ft_atoi(args[i]);
		j = i + 1;
		while (j < nbr_args)
		{
			if (arg_to_int == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
