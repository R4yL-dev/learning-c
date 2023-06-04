/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:49:22 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 20:11:27 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	nbrs_args(int argc);
static void	args_convert(int argc, char **argv, int *resp);
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
	args_convert(argc, argv, resp);
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

static void	args_convert(int argc, char **argv, int *resp)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_atoi(argv[i]);
		resp[i] = ft_atoi(argv[i]);
		i++;
	}
}

static int	args_valide(int argc, int *resp)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (resp[i] < 1)
		{
			ft_puterror("Parameter values must be at least 1");
			free(resp);
			return (0);
		}
		i++;
	}
	if (argc == 5)
	{
		if (resp[4] < 1)
		{
			ft_puterror("Parameter values must be at least 1");
			free(resp);
			return (0);
		}
	}
	else
		resp[4] = -1;
	return (1);
}
