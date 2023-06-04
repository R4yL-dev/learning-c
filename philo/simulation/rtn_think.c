/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtn_think.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:19:04 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:13:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	rtn_think(t_philo *philo)
{
	if (!is_alive(philo))
		return (0);
	philo_talk(philo, "is thinking");
	return (1);
}
