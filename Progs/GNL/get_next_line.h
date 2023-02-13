/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 03:00:29 by lray              #+#    #+#             */
/*   Updated: 2023/02/11 04:28:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

 char	*get_next_line(int fd);
 int	as_newline(t_list *reserve);
 t_list	*ft_get_last(t_list *reserve);
 void	make_line(char **line, t_list *reserve);
 int	ft_strlen(const char *str);
 void	free_all(t_list *reserve);

#endif
