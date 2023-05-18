/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:49:22 by lray              #+#    #+#             */
/*   Updated: 2023/05/18 19:51:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	args_convert(char *str);

int	args_parser(int *argc, char ***argv, int *args)
{
	/*
		Je dois check si il y a 4 ou 5 args.
		Il faut que tous les args soit des int (atoi)
		Il faut convertir les millisecond en microsecond
	*/
	int	i;

	(*argc)--;
	(*argv)++;
	if ((*argc) < 4 || (*argc) > 5)
		return (0);
	i = 0;
	while (i < 4)
	{
		args[i] = args_convert((*argv)[i]);
		i++;
	}
	if ((*argc) == 5)
		args[4] = args_convert((*argv)[4]);
	else
		args[4] = 0;
	return (1);
}

static int	args_convert(char *str)
{
	int			resp;

	resp = ft_atoi(str);
	if (!resp)
	{
		ft_puterror("Args must be int");
		return (0);
	}
	return (resp);
}
