/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:49:22 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:30:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	nbrs_args(int argc);
static int	args_convert(int argc, char **argv, int *resp);
static int	args_valide(int argc, int *resp);

int	*args_parser(int argc, char **argv)
{
	int	*resp;

	argc--;
	argv++;
	if (!nbrs_args(argc))
		return (NULL);
	resp = malloc(sizeof(int) * 5);
	if (!resp)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	if (!args_convert(argc, argv, resp))
		return (NULL);
	if (!args_valide(argc, resp))
		return (NULL);
	return (resp);
}

static int	nbrs_args(int argc)
{
	if (argc < 4 || argc > 5)
	{
		ft_puterror("You need to input between 4 and 5 parameters.");
		return (0);
	}
	return (1);
}

static int	args_convert(int argc, char **argv, int *resp)
{
	int	i;
	int	conv;

	i = 0;
	while (i < argc)
	{
		conv = ft_atoi(argv[i]);
		if (!conv)
		{
			free(resp);
			ft_puterror("Parameters must be integer");
			return (0);
		}
		resp[i] = conv;
		i++;
	}
	return (1);
}

static int	args_valide(int argc, int *resp)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (i < 4)
	{
		if (resp[i] < 1)
			check = 1;
		i++;
	}
	if (argc == 5)
	{
		if (resp[4] < 1)
			check = 1;
	}
	else
		resp[4] = 0;
	if (check)
	{
		free(resp);
		ft_puterror("Parameters must be greater than zero");
		return (0);
	}
	return (1);
}
