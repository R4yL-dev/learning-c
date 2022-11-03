/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:43:22 by lray              #+#    #+#             */
/*   Updated: 2022/11/03 19:50:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Libère la mémoire de l'élément passé en argument en utilisant la
		fonction del puis avec free.
		La mémoire de next ne doit pas être free.

	Params :
		- lst : L'élément à free.
		- del : L'adresse de la fonction permettant de supprimer le contenu
			de l'élément

	Ret :
		Aucun
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
