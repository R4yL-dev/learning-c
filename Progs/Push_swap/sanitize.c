/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:49:29 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 02:12:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_args(int argc, int *argv);
static void swap(int *xp, int *yp);

int	*sanitize(int argc, char *argv[])
{
	int	*args;
	int *sorted_args;
	int	nbr_args;
	int	i;
	int	j;

	args = malloc(sizeof(int) * argc);
	sorted_args = malloc(sizeof(int) * argc);
	if (!sorted_args)
		return (NULL);
	nbr_args = argc;
	while (argc > 0)
	{
		sorted_args[argc] = ft_atoi(argv[argc]);
		args[argc] = ft_atoi(argv[argc]);
		argc--;
	}
	sort_args(nbr_args, sorted_args);
	i = 0;
	while (i < nbr_args)
	{
		j = 0;
		while (j < nbr_args)
		{
			if (args[i] == sorted_args[j])
				args[i] = j;
			j++;
		}
		i++;
	}
	free(sorted_args);
	return (args);
}

static void	sort_args(int argc, int *argv)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < argc - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < argc)
		{
			if (argv[j] < argv[min_idx])
				min_idx = j;
			j++;
		}
		swap(&argv[min_idx], &argv[i]);
		i++;
	}
}

static void swap(int *xp, int *yp)
{
	int	tmp;
	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}
