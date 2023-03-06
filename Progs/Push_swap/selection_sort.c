/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:39:16 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 18:41:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *xp, int *yp);

void	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < n)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

static void	swap(int *xp, int *yp)
{
	int	tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}
