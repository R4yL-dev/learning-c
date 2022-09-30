/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:51:28 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 19:45:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La foction ft_bzero supprime les données des n octets de mémoireen
*	partant de la location pointée par s, en écrivant le caractère '\0'.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n * sizeof(char));
}
