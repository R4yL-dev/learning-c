/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:13:15 by lray              #+#    #+#             */
/*   Updated: 2023/02/18 17:40:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putptr(uintptr_t addr);
int	ft_put10(int nbr);
int	ft_putu10(unsigned int nbr);
int	ft_put16(unsigned int nbr, char *set);

#endif
