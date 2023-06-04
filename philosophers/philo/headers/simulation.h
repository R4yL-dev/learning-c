/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:42:19 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 19:12:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"

void	simu_run(t_context *ctx);

void	*routine(void *arg);
void	*routine_solo(void *arg);
int		is_alive(t_philo *philo);
int		will_survive(t_philo *philo, int time_to_test);
void	calculate_sleep(t_philo *philo);

int		rtn_eat(t_philo *philo);
void	take_first_fork(t_philo *philo);
void	take_second_fork(t_philo *philo);
void	put_down_first_fork(t_philo *philo);
void	put_down_second_fork(t_philo *philo);
void	put_down_both_fork(t_philo *philo);

int		rtn_sleep(t_philo *philo);
int		rtn_think(t_philo *philo);

void	supervisor_run(t_context *ctx);
void	kill_all_philos(t_context *ctx);
int		have_eat_enough(t_context *ctx, t_philo *philo);
int		have_everybody_eat_enough(t_context *ctx);

#endif
