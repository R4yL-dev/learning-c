/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:38:17 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 03:11:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			*args;
	t_context	*ctx;

	args = args_parser(argc, argv);
	if (!args)
		return (1);
	ctx = context_init(args);
	if (!ctx)
		return (1);

	simu_run(ctx);
	context_delete(ctx);
	return (0);
}
