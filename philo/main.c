/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:38:17 by lray              #+#    #+#             */
/*   Updated: 2023/05/22 19:06:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			*args;
	t_context	*ctx;

	args = malloc(sizeof(int) * 5);
	if (!args)
	{
		ft_puterror("Malloc failed");
		return (1);
	}
	if (!args_parser(&argc, &argv, args))
	{
		free(args);
		return (1);
	}
	ctx = context_init(args);
	if (!ctx)
	{
		free(args);
		return (1);
	}
	free(args);
	//dbcontext(ctx);
	simulation_run(ctx);
	// RUN SIMU
	//thread_start(philos, args[0]);
	//thread_wait_end(philos, args[0]);
	//philos_delete(philos);
	// DELETE CTX
	return (0);
}
