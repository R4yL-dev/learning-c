/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:51:51 by lray              #+#    #+#             */
/*   Updated: 2022/11/01 23:58:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Écrit le caractère c sur le descripteur de fichier donnée.

	Params :
		- c : Le caractère à écrire.
		- fd : Le descripteur de fichier sur lequel écrire.

	Ret :
		- Aucun
*/

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
