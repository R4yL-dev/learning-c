/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:10:09 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 18:21:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int	*arr, int size)
{
	int	*resp;
	int	i;

	resp = malloc(sizeof(int) * size);
	if (!resp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		resp[i] = arr[i];
		i++;
	}
	return (resp);
}

void	apply_mask(int *arr, int *mask, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == mask[j])
				arr[i] = j;
			++j;
		}
		++i;
	}
	free(mask);
}
